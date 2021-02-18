#ifndef MYTABLE_H
#define MYTABLE_H

#include <QTableView>
#include <QPushButton>
#include <QGridLayout >

class MyTable : public QTableView, public QGridLayout
{
    Q_OBJECT
public:
    MyTable();

    // utils functions
    void set_row_column_size(int, int);

    // buttons
    QPushButton *find_numbers;
};

#endif // MYTABLE_H
