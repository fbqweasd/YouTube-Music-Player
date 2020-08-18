#include "playlist_add_form.h"
#include "ui_playlist_add_form.h"
#include "qdynamicbutton.h"
#include "playlist.h"

#include <QDebug>
#include <QMessageBox>

PlayList *playlist_view;

QLayout *Scroll;

PlayList_Add_Form::PlayList_Add_Form(QWidget *parent, QLayout *Scroll_Layout) :
    QWidget(parent),
    ui(new Ui::PlayList_Add_Form)
{
    ui->setupUi(this);
    Scroll = Scroll_Layout;
}

PlayList_Add_Form::~PlayList_Add_Form()
{
    delete ui;
}

void PlayList_Add_Form::on_confirm_butten_clicked()
{
    QDynamicButton *button = new QDynamicButton(this);
    QString input;

    input = ui->PlayList_Name_input->text();

    qDebug() << input.size();

    if(!input.size()){

        QMessageBox::about(0, "Error", "아무것도 입력하지 않음");

        delete button;
        return;
    }

    button->PlayList.name = input;
    button->setText(input);
    Scroll->addWidget(button);

    connect(button, SIGNAL(clicked()), this, SLOT(slotGetNumber()));
    this->close();
}

void PlayList_Add_Form::on_cancel_butten_clicked()
{
    this->close();
}

void PlayList_Add_Form::slotGetNumber() // 버튼 클릭시 반응
{
    QDynamicButton *button = (QDynamicButton*) sender();
    //ui->Play_name->setText(QString::number(button->getID()));
    qDebug() << button->getID();

    if(!playlist_view){
        playlist_view = new PlayList(NULL, button);
        playlist_view->show();
        playlist_view = nullptr;
    }
}
