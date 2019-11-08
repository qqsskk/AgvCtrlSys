#include "CustomJsonModel.h"

CustomJsonModel::CustomJsonModel(const QJsonArray &src, QObject *parent)
    : QAbstractTableModel(parent)
    , m_src(src)
    , m_rowCount(src.count())
{
    if (m_rowCount > 0) {
        for (auto it = m_src.constBegin(); it != m_src.constEnd(); ++it) {
            if (it->isObject()) {
                m_data.push_back(it->toObject().toVariantMap());
            }
        }
        m_vmapHead = m_data.front();
        m_columnCount = m_vmapHead.count();
        m_headers = std::make_unique<QString[]>(m_columnCount);
        auto keys = m_vmapHead.keys();
        int i = 0;
        for (const auto &each : keys) {
            m_headers[i++] = each;
        }
    }
}

int	CustomJsonModel::columnCount(const QModelIndex &parent) const {
    return m_columnCount;
}

QString CustomJsonModel::currencyAt(int offset) const {
    return (m_vmapHead.begin() + offset).key();
}

QVariant CustomJsonModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return QVariant();

    if (role == Qt::TextAlignmentRole) {
        return int(Qt::AlignRight | Qt::AlignVCenter);
    }
    else if (role == Qt::DisplayRole) {
        const auto row = m_data.at(index.row());
        return row.find(m_headers[index.column()]).value();
    }
    return QVariant();
}

int	CustomJsonModel::rowCount(const QModelIndex &parent) const {
    return m_rowCount;
}

QVariant CustomJsonModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal)
        {
            return m_headers[section];
        }
    }

    return QVariant();
}
