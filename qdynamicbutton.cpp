#include "qdynamicbutton.h"

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

int QDynamicButton::ResID = 0;
