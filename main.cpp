
#include <QtWidgets>
#include <bits/stdc++.h>

int main(int argc, char **argv)
{

    QApplication app(argc, argv);

    // TASK 1
    // TASK 2 VARIANT 2
    // 2. Дана строка. Вывести строку, содержащую те же символы, но расположенные в обратном порядке.

    QWidget mainWidget;
    QBoxLayout *mainField = new QBoxLayout(QBoxLayout::BottomToTop);

    QTextEdit *textEdit = new QTextEdit();
    textEdit->setReadOnly(true);

    QLineEdit *button = new QLineEdit;
    QPushButton *pcmdNormal = new QPushButton("&Push me down!");

    // event listener on button
    mainWidget.connect(pcmdNormal, &QPushButton::pressed,
                       [textEdit, button]() {
                           QString inside = button->text();

                           button->setText("");
                           if (inside.size() > 0)
                           {
                               // TASK 1
                               textEdit->append("Your input: " + inside);
                               QString strUpper = inside.toUpper();
                               QString strLower = inside.toLower();
                               textEdit->append("Lower: " + strLower);
                               textEdit->append("Upper: " + strUpper);
                               // TASK 2
                               QString strReverse = inside;
                               std::reverse(strReverse.begin(), strReverse.end());
                               textEdit->append("Reversed: " + strReverse);
                           }
                       });

    // add widgets
    mainField->addWidget(textEdit);
    mainField->addWidget(pcmdNormal);
    mainField->addWidget(button);

    mainField->addStretch(0);

    mainWidget.resize(250, 250);
    mainWidget.setLayout(mainField);
    mainWidget.show();

    return app.exec();
}
