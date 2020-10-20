#ifndef YOUTUBE_H
#define YOUTUBE_H

#include <QString>
#include <QTextStream>
#include <QUrl>

#include <QNetworkAccessManager>
#include <QEventLoop>
#include <QNetworkReply>
#include <QLabel>

#include <QPixmap>

void get_youtube_thumbnail(QString code, QString *output);
void LoadAvatar(QString strAvatarUrl, QPixmap *pixmap);
void apply_Thumbnail(QString url, QLabel *thumbnail);
void get_youtube_url(QString code, QString *output);
QString reg_youtube_link(QString YouTubeLink);

#endif // YOUTUBE_H
