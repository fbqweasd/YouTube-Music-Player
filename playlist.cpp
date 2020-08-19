#include "playlist.h"
#include "ui_playlist.h"

PlayList::PlayList(QWidget *parent, QDynamicButton *par_button) :
    QWidget(parent),
    ui(new Ui::PlayList)
{
    ui->setupUi(this);

    ui->groupBox->setTitle(par_button->PlayList.name + " PlayList");

    if(!par_button->PlayList.Data){
        PlayList_Data *tmep = par_button->PlayList.Data;

        while(tmep){
            // 대충 버튼 추가하는 소스코드
        }
    }
}

PlayList::~PlayList()
{
    delete ui;
}
