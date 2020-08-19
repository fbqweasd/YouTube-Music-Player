#ifndef PLAYLIST_ADD_FORM_H
#define PLAYLIST_ADD_FORM_H

#include <QWidget>
#include <qdynamicbutton.h>

namespace Ui {
class PlayList_Add_Form;
}

class PlayList_Add_Form : public QWidget
{
    Q_OBJECT

public:
    explicit PlayList_Add_Form(QWidget *parent = nullptr, QLayout *Scroll_Layout = nullptr);
    ~PlayList_Add_Form();

private slots:
    void on_confirm_butten_clicked();

    void on_cancel_butten_clicked();

    void slotGetNumber();

private:
    Ui::PlayList_Add_Form *ui;
};

#endif // PLAYLIST_ADD_FORM_H
