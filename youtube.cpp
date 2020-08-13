#include "youtube.h"

void get_youtube_thumbnail(QString code, QString *output){

    if(code.size()){
        QTextStream(output) << "http://img.youtube.com/vi/" << code << "/hqdefault.jpg";
        //480 x 360 size
    }

    return;
}

void LoadAvatar(QString strAvatarUrl, QPixmap *pixmap)
{
   QUrl url(strAvatarUrl);
   QNetworkAccessManager manager;
   QEventLoop loop;

   QNetworkReply *reply = manager.get(QNetworkRequest(url));
   QObject::connect(reply, &QNetworkReply::finished, &loop, [&reply, pixmap,&loop](){
    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray jpegData = reply->readAll();
        pixmap->loadFromData(jpegData);
    }
    else{
        qDebug() << "Error : Img get Error " << reply->error();
    }
    loop.quit();
  });

  loop.exec();
}

void apply_Thumbnail(QString url, QLabel *thumbnail){

    QString thumbnail_path;
    QPixmap *buffer;

    get_youtube_thumbnail(QString(url), &thumbnail_path);

    qDebug() << thumbnail_path;

    buffer = new QPixmap();  //버퍼로 사용할 QPixmap 선언
    LoadAvatar(thumbnail_path, buffer);

    *buffer = buffer->scaled(480, 360);

    thumbnail->setPixmap(*buffer);
}
