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
    explicit PlayList(QWidget *parent = nullptr, QDynamicButton *par_button = nullptr);
    ~PlayList();

private:
    Ui::PlayList *ui;
};

#endif // PLAYLIST_H
