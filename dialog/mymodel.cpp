#include "mymodel.h"



MyModel::MyModel(QObject *parent, int _rows_count, int _columns_count)
    : QAbstractTableModel(parent)
{
    rows_count = _rows_count;
    columns_count = _columns_count;

    for(int i=0; i<this->rows_count; i++){
        vector<int> temp;
        for(int j=0; j<this->columns_count; j++){
            temp.push_back(random_generator(0, 100));
        }
        input_data.push_back(temp);
    }
}

int MyModel::random_generator(int start, int end) {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(start, end); // define the range

    return distr(gen);
}

int MyModel::rowCount(const QModelIndex &) const
{
    return rows_count;
}

int MyModel::columnCount(const QModelIndex &) const
{
    return columns_count;
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
        return input_data[index.row()][index.column()];

    return QVariant();
}
