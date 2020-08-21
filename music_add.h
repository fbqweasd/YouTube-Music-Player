#ifndef MUSIC_ADD_H
#define MUSIC_ADD_H

#include <QWidget>
#include "qdynamicbutton.h"

namespace Ui {
class Music_Add;
}

class Music_Add : public QWidget
{
    Q_OBJECT

public:
    explicit Music_Add(QWidget *parent = nullptr, QDynamicButton *par_button = nullptr, QLayout *Scroll_Layout = nullptr);
    ~Music_Add();

private slots:
    void on_Add_Button_clicked();

    void on_Cancel_Button_clicked();

    void Music_Click_Listener();

private:
    Ui::Music_Add *ui;
};

#endif // MUSIC_ADD_H
