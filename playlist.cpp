#include "playlist.h"
#include "ui_playlist.h"

PlayList::PlayList(QWidget *parent, QDynamicButton *par_button) :
    QWidget(parent),
    ui(new Ui::PlayList)
{
    ui->setupUi(this);

    ui->groupBox->setTitle(par_button->PlayList.name + " PlayList");
}

PlayList::~PlayList()
{
    delete ui;
}
