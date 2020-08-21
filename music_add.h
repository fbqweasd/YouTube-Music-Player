#ifndef MUSIC_ADD_H
#define MUSIC_ADD_H

#include <QWidget>

namespace Ui {
class Music_Add;
}

class Music_Add : public QWidget
{
    Q_OBJECT

public:
    explicit Music_Add(QWidget *parent = nullptr);
    ~Music_Add();

private:
    Ui::Music_Add *ui;
};

#endif // MUSIC_ADD_H
