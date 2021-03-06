#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtNetwork>
#include <QDebug>
#include <QScrollArea>
#include <QMessageBox>
#include <QImage>
#include <QtXml>
#include <QMediaPlayer>
#include <QMediaPlaylist>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void tcpInit();
    int apply_youtube(QString youtube_link);

private slots:
    void on_PlayListAddButton_clicked();
    void on_pushButton_2_clicked();

    // TCP
    void newConnection();
    void readData();
    void disConnected();
    void sendValue(int temp, int hum, int dust, int human);

private:
    Ui::Widget *ui;
    QTcpServer* tcpServer;
    QTcpSocket* client;

//    struct Private;
//    Private * d;

    int con;
};
#endif // WIDGET_H
