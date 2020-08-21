#include "qdynamicbutton.h"

int QDynamicButton::ResID = 0;

QDynamicButton::QDynamicButton(QWidget *parent) :
    QPushButton(parent)
{
    ResID++;
    buttonID = ResID;
}

QDynamicButton::~QDynamicButton()
{
    ResID--;
}

int QDynamicButton::getID()
{
    return buttonID;
}

PlayList_Button::PlayList_Button(QWidget *parent)
    : QPushButton(parent)
{
    Data.name = nullptr;
}

PlayList_Button::~PlayList_Button(){

}
