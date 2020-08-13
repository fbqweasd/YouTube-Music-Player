#include "widget.h"
#include "ui_widget.h"
#include "youtube.h"

#include <QDebug>
#include <QScrollArea>
#include <QMessageBox>
#include <QImage>

QImage *Img;
QPixmap *buffer;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->scrollArea->setBackgroundRole(QPalette::Dark);

    Img = new QImage();       //이미지를 로드하기 위한 QImage 선언
    buffer = new QPixmap();  //버퍼로 사용할 QPixmap 선언

    if(Img->load("C:\\Users\\UKC\\Documents\\Git\\YouTube_Player\\Test_img\\Test_img_2.jpg"))      //이미지 로드
    {
        *buffer = QPixmap::fromImage(*Img);   //이미지를 버퍼에 옮긴다.

        //*buffer = buffer->scaledToWidth(ui->Thumbnail->width());
        *buffer = buffer->scaledToHeight(ui->Thumbnail->height());

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
    apply_Thumbnail("A018qr6KlgM", ui->Thumbnail);
}
