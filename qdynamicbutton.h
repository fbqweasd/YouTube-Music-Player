#ifndef QDYNAMICBUTTON_H
#define QDYNAMICBUTTON_H

#include <QWidget>
#include <QPushButton>

struct PlayList_Titie{

    QString name;

    struct PlayList_Data *Data;
};

struct PlayList_Data{

    QString name;

    QString YouTube_code;

    struct PlayList_Data *next;
};

class QDynamicButton : public QPushButton
{
public:
    QDynamicButton(QWidget *parent = 0);
    ~QDynamicButton();
    static int ResID;
    int getID();
    struct PlayList_Titie PlayList;

public slots:

private:
    int buttonID = 0;
};

#endif // QDYNAMICBUTTON_H
