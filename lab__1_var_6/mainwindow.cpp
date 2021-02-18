#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent, int _matrix_height, int _matrix_width, vector<int> odd_numbers) : QWidget(parent)
{
    // set props
    matrix_height = _matrix_height;
    matrix_width = _matrix_width;
    numbers_for_odd = odd_numbers;

    CreateTableWidget();
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(verticalGroupBox);
    setLayout(mainLayout);

    // create shortcuts
    CreateShortcuts();

    // add connect
    CreateConnects();

    // main window styles
    resize(600, 400);
}


void MainWindow::CreateTableWidget(){
    verticalGroupBox = new QGroupBox(tr("Table numbers"));
    QVBoxLayout *layout = new QVBoxLayout;

    // create table widget
    table_widget = new QTableWidget(matrix_height, matrix_width, this);
    table_widget->horizontalHeader()->hide();
    table_widget->verticalHeader()->hide();


    for(int i=0; i<matrix_height; i++){
        vector<int> temp;
        for(int j=0; j<matrix_width; j++){
            int rand_num = random_generator(1, 50);
            temp.push_back(rand_num);

            QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg(QString::number(rand_num)));
            // add hover event
            newItem->setToolTip(tr("Item have value = %1").arg(rand_num));

            table_widget->setItem(i, j, newItem);
        }
        input_data.push_back(temp);
    }

    for(int i=0; i<matrix_width; i++)
        table_widget->setColumnWidth(i, 20);

    // add button
    find_numbers_button = new QPushButton("find numbers");
    reset_numbers_button = new QPushButton("reset numbers");

    // add label
    numbers_info = new QLabel("");

    // add to widget
    layout->addWidget(table_widget);
    layout->addWidget(numbers_info);
    layout->addWidget(find_numbers_button);
    layout->addWidget(reset_numbers_button);

    verticalGroupBox->setLayout(layout);
}

void MainWindow::FindSpecialNumbers(){
    int ammount = 0;
    for(int i=0; i<matrix_height; i++){
        for(int j=0; j<matrix_width; j++){
            int number_item = input_data[i][j];
            qInfo() << number_item << "\n";
            if(check_numbers_for_odd(number_item)){
                QTableWidgetItem *item = table_widget->takeItem(i, j);

                item->setBackground(QBrush(QColor(99, 209, 180)));
                table_widget->setItem(i, j, item);

                ammount += 1;
            }
        }
    }

    // Set Text
    numbers_info->setText(tr("Elements found -> %1").arg(QString::number(ammount)));
}

void MainWindow::ResetNumbers(){
    input_data.clear();

    for(int i=0; i<matrix_height; i++){
        vector<int> temp;
        for(int j=0; j<matrix_width; j++){
            int rand_num = random_generator(1, 50);
            temp.push_back(rand_num);

            QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg(QString::number(random_generator(1, 100))));
            table_widget->setItem(i, j, newItem);
        }
        input_data.push_back(temp);
    }

    for(int i=0; i<matrix_width; i++)
        table_widget->setColumnWidth(i, 20);
}

void MainWindow::CreateConnects(){
    // connect buttons
    connect(find_numbers_button, SIGNAL(clicked()), SLOT(FindSpecialNumbers()));
    connect(reset_numbers_button, SIGNAL(clicked()), SLOT(ResetNumbers()));

    // connect shortcuts
    connect(CtrlA, SIGNAL(activated()), SLOT(FindSpecialNumbers()));
    connect(CtrlS, SIGNAL(activated()), SLOT(ResetNumbers()));
}

void MainWindow::CreateShortcuts(){
    // Ctrl+A
    CtrlA = new QShortcut(QKeySequence(tr("Ctrl+A")), this);

    // Ctrl+S
    CtrlS = new QShortcut(QKeySequence(tr("Ctrl+S")), this);
}

bool MainWindow::check_numbers_for_odd(int number){
    bool is_colored = false;
    for(int odd_num : numbers_for_odd)
        if(number % odd_num == 0){
            is_colored = true;
            break;
        }
    return is_colored;
}

int MainWindow::random_generator(int start, int end) {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(start, end); // define the range

    return distr(gen);
}
