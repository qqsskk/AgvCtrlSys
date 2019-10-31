#include "Config.h"

Config::Config(QString fileName)
{
    if (fileName.isEmpty())
    {
        m_fileName = QCoreApplication::applicationDirPath() + "/config.ini";
    }
    else
    {
        m_fileName = fileName;
    }
    m_setting = new QSettings(m_fileName, QSettings::IniFormat);
}

Config::~Config()
{
    if(m_setting)
    {
        delete m_setting;
        m_setting = nullptr;
    }
}

void Config::set(QString nodeName, QString keyName, QVariant value)
{
    m_setting->setValue(QString("/%1/%2").arg(nodeName).arg(keyName), value);
}

QVariant Config::get(QString nodeName, QString keyName)
{
    QVariant qvar = m_setting->value(QString("/%1/%2").arg(nodeName).arg(keyName));
    return qvar;
}
