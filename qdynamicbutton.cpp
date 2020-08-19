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
