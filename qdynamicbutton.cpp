#include "qdynamicbutton.h"

QDynamicButton::QDynamicButton(QWidget *parent) :
    QPushButton(parent)
{
    ResID++;
    buttonID = ResID;
}

QDynamicButton::~QDynamicButton()
{
}

int QDynamicButton::getID()
{
    return buttonID;
}

int QDynamicButton::ResID = 0;
