#include "playlist_add_form.h"
#include "ui_playlist_add_form.h"

PlayList_Add_Form::PlayList_Add_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayList_Add_Form)
{
    ui->setupUi(this);
}

PlayList_Add_Form::~PlayList_Add_Form()
{
    delete ui;
}
