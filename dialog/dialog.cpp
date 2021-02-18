#include <QtWidgets>
#include <QTableWidgetItem>

#include "dialog.h"
#include "mymodel.h"

//! [0]
Dialog::Dialog()
{
    createHorizontalGroupBox();


    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout->addWidget(horizontalGroupBox);

    setLayout(mainLayout);

    setWindowTitle(tr("Basic Layouts"));
}

void Dialog::createHorizontalGroupBox()
{
    horizontalGroupBox = new QGroupBox(tr("Horizontal layout"));
    QVBoxLayout *layout = new QVBoxLayout;

    // create table widget
    table_widget = new QTableWidget(3, 3, this);
    QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg((1)*(1)));

    for()
    table_widget->setItem(1, 1, newItem);


    layout->addWidget(table_widget);
    horizontalGroupBox->setLayout(layout);

}


