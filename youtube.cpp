#include "youtube.h"

/**
 * @brief Get the youtube thumbnail url
 * 
 * @param code youtube play code
 * @param output String ouput
 */

void get_youtube_thumbnail(QString code, QString *output){

    if(code.size()){
        QTextStream(output) << "http://img.youtube.com/vi/" << code << "/hqdefault.jpg";
        //480 x 360 size
    }

    return;
}

/**
 * @brief Get the youtube url
 *
 * @param code youtube play code
 * @param output String ouput
 */

void get_youtube_url(QString code, QString *output){

    if(!code.isNull()){
        QTextStream(output) << "https://www.youtube.com/embed/" << code;
    }
    return;
}

/**
 * @brief url 에서 pixmap 데이터를 가지고 오는 함수, 내부적으로 동작
 * 
 * @param strAvatarUrl 불러올 url
 * @param pixmap 반환받을 pixmap 값
 */

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

/**
 * @brief 유튜브 재생 코드를 인자 값으로 받아 라벨에 썸네일을 등록 하는 함수
 * 
 * @param code 유튜브 재생 코드
 * @param thumbnail 등록할 라벨
 */

void apply_Thumbnail(QString code, QLabel *thumbnail){

    QString thumbnail_path;
    QPixmap *buffer;

    get_youtube_thumbnail(QString(code), &thumbnail_path); // code -> Thumbnail Url
    qDebug() << thumbnail_path;

    buffer = new QPixmap();  
    LoadAvatar(thumbnail_path, buffer);

    *buffer = buffer->scaled(480, 360);

    thumbnail->setPixmap(*buffer);
}

QString reg_youtube_link(QString YouTubeLink){
    QString output;
    QRegExp rx("https://youtu.be/([a-zA-Z0-9\\-_]+)");
    rx.indexIn(YouTubeLink);
    QStringList List = rx.capturedTexts();

    foreach(output, List);

    return output;
}
