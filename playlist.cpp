#include "playlist.h"
#include "ui_playlist.h"

#include "music_add.h"

static QLayout *Scroll;
static int current_num;
static Music_Add *Music_From;

PlayList::PlayList(QWidget *parent, QDynamicButton *par_button, QLayout *Scroll_Layout, int num) :
    QWidget(parent),
    ui(new Ui::PlayList)
{
    ui->setupUi(this);

    Scroll = Scroll_Layout;
    current_num = num;
    ui->groupBox->setTitle(par_button->PlayList.name + " PlayList");

    if(!par_button->PlayList.Data){
        PlayList_Data *tmep = par_button->PlayList.Data;

        while(tmep){
            // 대충 버튼 추가하는 소스코드

            tmep = tmep->next;
        }
    }
}

PlayList::~PlayList()
{
    delete ui;
}

void PlayList::on_Play_Add_Button_clicked()
{
    // 음악 목록을 추가하는 UI 띄우기
    if(!Music_From){
        Music_From = new Music_Add(NULL);
        Music_From->show();
        Music_From = nullptr;
    }
}

void PlayList::on_Cancel_Button_clicked()
{
    // 창닫는 기능 수행
    this->close();
}

void PlayList::on_pushButton_3_clicked()
{
    // 현재 이 재생목록을 삭제하는 기능 수행
    QLayoutItem *item;
    item = Scroll->takeAt(current_num);

    if(item->widget()){
        delete item->widget();
    }
    delete item;
    this->close();
}
