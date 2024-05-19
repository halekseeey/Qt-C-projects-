#include "mytablemodel.h"

MyTableModel::MyTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

int MyTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_map.size();
}

int MyTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 1; // One column for combined key-value display
}

QVariant MyTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    int row = index.row();
    int key = m_keys.at(row);

    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        return QString("%1: %2").arg(key).arg(m_map.value(key));
    }

    return QVariant();
}

bool MyTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid() || role != Qt::EditRole)
        return false;

    int row = index.row();
    QStringList parts = value.toString().split(": ");
    if (parts.size() != 2)
        return false;

    bool keyOk;
    int newKey = parts[0].toInt(&keyOk);
    QString newValue = parts[1];

    if (!keyOk)
        return false;

    int oldKey = m_keys.at(row);

    if (newKey != oldKey && m_map.contains(newKey)) {
        // Key already exists
        return false;
    }

    // Update map
    m_map.remove(oldKey);
    m_map.insert(newKey, newValue);
    m_keys[row] = newKey;

    emit dataChanged(index, index, {role});
    return true;
}

Qt::ItemFlags MyTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

void MyTableModel::setMap(const QMap<int, QString> &map)
{
    beginResetModel();
    m_map = map;
    m_keys = map.keys();
    endResetModel();
}

QMap<int, QString> MyTableModel::map() const
{
    return m_map;
}
