#include "widget.h"
#include "ui_widget.h"

#include <QDebug>
#include <QScrollArea>
#include <QImage>
#include <QLabel>
#include <QMessageBox>

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

    if(Img->load("C:\\Users\\UKC\\Documents\\Git\\YouTube_Player\\Test_img\\Test_img_2.jpg"))      //이미지를 로드한다.
    {
        *buffer = QPixmap::fromImage(*Img);   //이미지를 버퍼에 옮긴다.
        //*buffer = buffer->scaled(Img->width(),Img->height()); //이미지 사이즈 조절

        *buffer = buffer->scaledToWidth(ui->Thumbnail->width());

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


void Widget::on_AddButton_clicked()
{



    qDebug() << "AddButton Clicked!!";
}
