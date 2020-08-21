#include "music_add.h"
#include "ui_music_add.h"

Music_Add::Music_Add(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Music_Add)
{
    ui->setupUi(this);
}

Music_Add::~Music_Add()
{
    delete ui;
}
