#include "mainwindow.h"

#include <QApplication>

#include "mymodel.h"
#include "mytable.h"

#include <iostream>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    int height = 4;
    int width = 4;
    MyTable mytable;

    MyModel myModel(nullptr, height, width);
    mytable.setModel(&myModel);
    mytable.set_row_column_size(20, 20);

    return a.exec();
}
