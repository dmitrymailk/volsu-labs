#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QTableWidget>
#include <QGroupBox>

// c++ modules
#include <vector>
#include <random>

using namespace std;

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent, int, int, vector<int>);

    // functions
    void CreateTableWidget();

    // mytable
    QTableWidget *table_widget;
    QGroupBox *verticalGroupBox;

    //properties
    int matrix_height;
    int matrix_width;
    vector<vector<int>> input_data;
    vector<int> numbers_for_odd;

    // utils functions
    static int random_generator(int, int);
    bool check_numbers_for_odd(int);

    // buttons
    QPushButton *find_numbers_button;
    QPushButton *reset_numbers_button;

    // labels
    QLabel *numbers_info;
private slots:
    void FindSpecialNumbers();
    void ResetNumbers();
};

#endif // MAINWINDOW_H
