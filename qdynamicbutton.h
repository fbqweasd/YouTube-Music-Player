#ifndef QDYNAMICBUTTON_H
#define QDYNAMICBUTTON_H

#include <QWidget>
#include <QPushButton>

class QDynamicButton : public QPushButton
{
public:
    QDynamicButton(QWidget *parent = 0);
    ~QDynamicButton();
    static int ResID;
    int getID();

public slots:

private:
    int buttonID = 0;
};

#endif // QDYNAMICBUTTON_H
