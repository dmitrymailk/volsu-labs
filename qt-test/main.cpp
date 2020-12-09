
#include <QtWidgets>

int main(int argc, char **argv)
{

    QApplication app(argc, argv);

    QWidget mainWidget;
    QBoxLayout *mainField = new QBoxLayout(QBoxLayout::TopToBottom);

    QTextEdit *textEdit = new QTextEdit();
    textEdit->setReadOnly(true);

    //    QLineEdit *input = new QLineEdit();
    QPushButton *addButton = new QPushButton("&Add to field below!");
    QPushButton *clearButton = new QPushButton("&Clear output.");

    QRadioButton *radioButtonStars = new QRadioButton("***");
    QRadioButton *radioButtonEquals = new QRadioButton("===");
    QCheckBox *isAddSurname = new QCheckBox("Add surname?");

    QString appSurname = "Kosenko";
    QString appName = "Dmitry";

    QFont inputFont("Arial", 20, QFont::Bold, true);

    QVBoxLayout *layout = new QVBoxLayout();


    textEdit->setFont(inputFont);

    mainWidget.connect(addButton, &QPushButton::pressed,
                       [radioButtonStars, radioButtonEquals, appSurname, appName, isAddSurname, layout]() {
                          QString resutString;
                          if (radioButtonEquals->isChecked())
                           {
                               if (isAddSurname->isChecked())
                                   resutString = appSurname + " === " + appName;
                               else
                                   resutString = " === " + appName;
                           }
                           if (radioButtonStars->isChecked())
                           {
                               if (isAddSurname->isChecked())
                                   resutString = appSurname + " *** " + appName;
                               else
                                   resutString = " *** " + appName;
                           }
                        QLabel *label = new QLabel();
                        label->setText(resutString);
                        layout->addWidget(label);
                       });
    mainWidget.connect(clearButton, &QPushButton::pressed,
                       [textEdit, layout]() {
                        if (layout) {
                                while(layout->count() > 0){
                                    QLayoutItem *item = layout->takeAt(0);
                                    QWidget* widget = item->widget();
                                    if(widget)
                                        delete widget;
                                    delete item;
                                }
                            }

                       });

//    layout->SetMinimumSize();
//    mainField->addWidget(textEdit);
    mainField->addWidget(clearButton);
    mainField->addWidget(addButton);

    mainField->addWidget(radioButtonStars);
    mainField->addWidget(radioButtonEquals);
    mainField->addWidget(isAddSurname);
    mainField->addLayout(layout);

    mainField->addStretch(0);

    mainWidget.resize(450, 450);
    mainWidget.setLayout(mainField);
    mainWidget.setWindowTitle("Kosenko  Dmitry Super Application");
    mainWidget.show();

    return app.exec();
}
