#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    vector<int> numbers_array = {2, 3, 4, 5, 6};
    MainWindow w(nullptr, 7, 7, numbers_array);
    w.show();
    return a.exec();
}
