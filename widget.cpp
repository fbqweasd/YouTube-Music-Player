#include "widget.h"
#include "ui_widget.h"
#include "youtube.h"

#include "playlist_add_form.h"
#include "qdynamicbutton.h"

#include <QDebug>
#include <QScrollArea>
#include <QMessageBox>
#include <QImage>
#include "path.h"

QImage *Img;
QPixmap *buffer;

PlayList_Add_Form *Form;

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

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_PlayListAddButton_clicked()
{
    apply_Thumbnail("NmY6wo3rEso", ui->Thumbnail);


    if(!Form){
        Form = new PlayList_Add_Form(NULL, ui->PlayList_Layout);
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


