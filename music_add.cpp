#include "music_add.h"
#include "ui_music_add.h"

#include <QMessageBox>
#include <qdynamicbutton.h>
#include <QDebug>

struct QLayout *Scroll;
struct QDynamicButton *PlayList;

Music_Add::Music_Add(QWidget *parent,QDynamicButton *par_button, QLayout *Scroll_Layout) :
    QWidget(parent),
    ui(new Ui::Music_Add)
{
    ui->setupUi(this);

    Scroll = Scroll_Layout;
    PlayList = par_button;
}

Music_Add::~Music_Add()
{
    delete ui;
}

void Music_Add::on_Add_Button_clicked()
{
    PlayList_Button *button = new PlayList_Button(this);
    QString input_name, input_url;

    input_name = ui->Music_Name_input->text();
    input_url = ui->url_input->text();

    if(!input_name.size() || !input_url.size()){

        QMessageBox::about(0, "Error", "입력하지 않은 데이터가 있습니다.");

        delete button;
        return;
    }

    button->Data.name = input_name;
    button->setText(input_name);
    Scroll->addWidget(button);

    connect(button, SIGNAL(clicked()), this, SLOT(Music_Click_Listener()));

    if(!PlayList->PlayList.Data){
        PlayList->PlayList.Data = button;
        PlayList->PlayList.Last_Data = button;
    }
    else{
        PlayList->PlayList.Last_Data->Data.next = button;
        PlayList->PlayList.Last_Data = button;
    }
    this->close();
}

void Music_Add::on_Cancel_Button_clicked()
{
    this->close();
}

void Music_Add::Music_Click_Listener()
{

}
