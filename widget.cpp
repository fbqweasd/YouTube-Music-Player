#include "widget.h"
#include "ui_widget.h"
#include "youtube.h"

#include "playlist_add_form.h"
#include "qdynamicbutton.h"

#include "path.h"

QImage *Img;
QPixmap *buffer;
QLabel *Thumbnail;
QMediaPlayer *player;
QMediaPlaylist *playlist;

PlayList_Add_Form *Form;

static inline qint32 ArrayToInt(QByteArray source);
int apply_youtube(QString youtube_link);

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->scrollArea->setBackgroundRole(QPalette::Dark);

    Img = new QImage();       //이미지를 로드하기 위한 QImage 선언
    buffer = new QPixmap();  //버퍼로 사용할 QPixmap 선언
    QString defalt_img;
    defalt_img = IMG_PATH;
    defalt_img.append("Test_img_2.jpg");
    Thumbnail = ui->Thumbnail;


    if(Img->load(defalt_img))      //이미지 로드
    {
        *buffer = QPixmap::fromImage(*Img);   //이미지를 버퍼에 옮긴다.

        *buffer = buffer->scaledToWidth(Img->width());
        //*buffer = buffer->scaledToHeight(Img->height());

        ui->Thumbnail->setPixmap(*buffer);
    }
    else
    {
        //QMessageBox::about(0, "Image Error", "Image load Error");
        qDebug() << "Img load Error";
    }

    ui->Like_num->setText("20");
    qDebug() << ui->Like_num;

    tcpInit();
}

Widget::~Widget()
{
    QDynamicButton current_Button;
    QLayoutItem *temp;
    temp = ui->PlayList_Layout->takeAt(0);

    delete ui;
}

void Widget::on_PlayListAddButton_clicked()
{
    apply_youtube("NmY6wo3rEso");

    qDebug() << Form;


    if(!Form){ // Form은 여러 창이 뜨지 않도록 해주는 역할 수행, 소멸자에 Form 값을 넣을 수 없어서 정상동작 X
        Form = new PlayList_Add_Form(NULL, ui->PlayList_Layout); // 새로운 버튼 생성
        Form->show();
        Form = nullptr;
    }
}

void Widget::on_pushButton_2_clicked()
{
    QDynamicButton *button = new QDynamicButton(this);
    button->setText("동적 생성 버튼 " + QString::number(button->getID()));
    ui->PlayList_Layout->addWidget(button);

    connect(button, SIGNAL(clicked()), this, SLOT(slotGetNumber()));
}

void Widget::tcpInit()
{
    QHostAddress hostAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();

    for(int i = 0; i < ipAddressesList.size(); ++i){
        if(ipAddressesList.at(i) != QHostAddress::LocalHost && ipAddressesList.at(i).toIPv4Address()){
            hostAddress = ipAddressesList.at(i);
            break;
        }
    }

    if(hostAddress.toString().isEmpty()){
        hostAddress = QHostAddress(QHostAddress::LocalHost);
    }

    tcpServer = new QTcpServer(this);
    if(!tcpServer->listen(hostAddress, 5656)){
        qDebug() << "connet Failed";
        close();
    }
    else {
        qDebug() << "Tcp Server Open";
    }
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(newConnection()));
}

void Widget::newConnection(){
    qDebug() << "connet : " << con;

    if(con == 0){
        client = tcpServer->nextPendingConnection();
        con++;

        connect(client, SIGNAL(readyRead()), this, SLOT(readData()));
        connect(client, SIGNAL(disconnected()), this, SLOT(disConnected()));
        disconnect(tcpServer, SIGNAL(newConnection()), this, SLOT(newConnection()));
    }
}

void Widget::readData(){
     QByteArray data;

    if(client->bytesAvailable() >= 0){
        data = client->readAll();
    }

    qDebug() << "Read data : " + data;
}

void Widget::disConnected(){
    client->close();
    --con;

    if(con == 0){
        connect(tcpServer, SIGNAL(newConnection()), this, SLOT(newConnection()));
    }
}

void Widget::sendValue(int temp, int hum, int dust, int human){
    // 지금은 사용하지 않는 함수

    QByteArray tempbyte = QByteArray::number(temp);
    QByteArray humbyte = QByteArray::number(hum);
    QByteArray dustbyte = QByteArray::number(dust);
    QByteArray humanbyte = QByteArray::number(human);


}

int apply_youtube(QString youtube_link){
    apply_Thumbnail(youtube_link, Thumbnail);

    QString youtube_Link;
    player = new QMediaPlayer;
    playlist = new QMediaPlaylist(player);

    get_youtube_url(youtube_link, &youtube_Link);
    qDebug() << youtube_Link;

    playlist->addMedia(QUrl(youtube_Link));
    //playlist->addMedia(QUrl("http://example.com/myfile2.mp3"));

    playlist->setCurrentIndex(1);
    player->setPlaylist(playlist);
    player->setVolume(70);
    player->play();

    return 0;
}
