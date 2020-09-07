#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QWidget>
#include <qdynamicbutton.h>

namespace Ui {
class PlayList;
}

class PlayList : public QWidget
{
    Q_OBJECT

public:
    explicit PlayList(QWidget *parent = nullptr, QDynamicButton *par_button = nullptr, int num = -1, QLayout *PlayList_Scroll = nullptr);
    ~PlayList();

private slots:
    void on_Play_Add_Button_clicked();

    void on_Cancel_Button_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::PlayList *ui;
};

#endif // PLAYLIST_H
