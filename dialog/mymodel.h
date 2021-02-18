#ifndef MYMODEL_H
#define MYMODEL_H

#include <QAbstractTableModel>
#include <QtGlobal>

// c++ modules
#include <vector>
#include <random>

using namespace std;

class MyModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    MyModel(QObject *parent = nullptr, int _columns_count = 3, int _rows_count = 3);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // properties
    int columns_count;
    int rows_count;
    vector<vector<int>> input_data;

    // utils functions
    static int random_generator(int, int);
};

#endif // MYMODEL_H
