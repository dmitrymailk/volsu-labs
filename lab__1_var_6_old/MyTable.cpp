#include <mytable.h>

MyTable::MyTable() : QTableView(), QGridLayout()
{
    // buttons settings
    find_numbers = new QPushButton("Find numbers");
    find_numbers->setGeometry(100, 100, 40, 90);

    // add widgets
    QGridLayout::addWidget(find_numbers);

    QTableView::show();
    QTableView::setFixedSize(600, 400);

}

void MyTable::set_row_column_size(int _height, int _width){
    for(int i=0; i<_width; i++){
        this->setColumnWidth(i, _height);
        this->setRowHeight(i, _width);
    }
}
