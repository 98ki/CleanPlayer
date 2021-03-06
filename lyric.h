#ifndef LYRIC_H
#define LYRIC_H

#include <QObject>
#include<QString>
#include<QUrl>
#include<QList>
#include<QStack>

struct LyricLine{
    qint64 time;
    QString lyric;
};

class Lyric : public QObject
{
    Q_OBJECT
public:
    Lyric(QObject *parent = 0);
    Q_INVOKABLE void loadFile(const QString& lyricFile);

    //查询当前时间对应的歌词位置
    Q_INVOKABLE int getLyric(qint64 queryTime);
    Q_INVOKABLE int lineCount();
    //返回查询时间歌词的所在行数，同时将歌词写入lyricStr中
    Q_INVOKABLE int getLyric(qint64 queryTime,QString& lyricStr);
    Q_INVOKABLE QString lyricAt(int i);
    Q_INVOKABLE QList<LyricLine*> getLyricList();



signals:

public slots:

private:
    void parseLyricLine(const QString& line);
    void sort();
    //储存时间偏移
    int offset;

    //储存时间
    QStack<qint64> times;

    QList<LyricLine*> lyricList;

};

#endif // LYRIC_H
