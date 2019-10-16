#ifndef CONFIG_H
#define CONFIG_H

#include <QVariant>
#include <QSettings>
#include <QtCore/QtCore>
#include <QDebug>

class Config
{
public:
    Config(QString filename = "");
    virtual ~Config(void);
    void set(QString, QString, QVariant);
    QVariant get(QString, QString);
private:
    QString m_fileName;
    QSettings *m_setting;
};

#endif // CONFIG_H
