#ifndef CUSTOMJSONMODEL_H
#define CUSTOMJSONMODEL_H

#include <memory>
#include <QAbstractTableModel>
#include <QJsonObject>
#include <QJsonArray>

class CustomJsonModel : public QAbstractTableModel
{
public:
    CustomJsonModel(const QJsonArray &src, QObject *parent = Q_NULLPTR);
    int	columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    //QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    //QModelIndex parent(const QModelIndex &index) const override;
    int	rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
protected:
    QJsonArray m_src;
    int m_rowCount;
    int m_columnCount = 0;
    QVariantMap m_vmapHead;
    std::unique_ptr<QString[]> m_headers;
    QList<QVariantMap> m_data;
    QString currencyAt(int offset) const;

};
#endif // CUSTOMJSONMODEL_H
