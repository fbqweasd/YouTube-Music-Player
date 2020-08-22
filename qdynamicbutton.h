#ifndef QDYNAMICBUTTON_H
#define QDYNAMICBUTTON_H

#include <QWidget>
#include <QPushButton>

class PlayList_Button;

struct PlayList_Titie{

    QString name;

    PlayList_Button *Data;
    PlayList_Button *Last_Data;
};

struct PlayList_Data{

    QString name;

    QString YouTube_code;

    PlayList_Button *next;
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


class PlayList_Button : public QPushButton{

public:
    PlayList_Button(QWidget *parent = 0);
    ~PlayList_Button();

    struct PlayList_Data Data; // 이름, 재생 목록등 저장용

public slots:

private:

};


#endif // QDYNAMICBUTTON_H
