#ifndef PLAYLIST_ADD_FORM_H
#define PLAYLIST_ADD_FORM_H

#include <QWidget>

namespace Ui {
class PlayList_Add_Form;
}

class PlayList_Add_Form : public QWidget
{
    Q_OBJECT

public:
    explicit PlayList_Add_Form(QWidget *parent = nullptr);
    ~PlayList_Add_Form();

private:
    Ui::PlayList_Add_Form *ui;
};

#endif // PLAYLIST_ADD_FORM_H
