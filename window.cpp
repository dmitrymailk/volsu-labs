

#include "renderarea.h"
#include "colorlisteditor.h"

#include "window.h"

#include <QtWidgets>

// debug
#include <QTextStream>


Window::Window()
{
    renderArea = new RenderArea;

    radiusQSpinBox = new QSpinBox;
    radiusQSpinBox->setRange(1, 8);

    radiusLabel = new QLabel(tr("&Circle Radius:"));
    radiusLabel->setBuddy(radiusQSpinBox);

    axisXQSpinBox = new QSpinBox;
    axisXQSpinBox->setRange(100, 400);

    axisXQSpinBoxLabel = new QLabel(tr("Change center on axis X:"));
    axisXQSpinBoxLabel->setBuddy(axisXQSpinBox);


    axisYQSpinBox = new QSpinBox;
    axisYQSpinBox->setRange(100, 400);

    axisYQSpinBoxLabel = new QLabel(tr("Change center on axis Y:"));
    axisYQSpinBoxLabel->setBuddy(axisYQSpinBox);

    connect(radiusQSpinBox, QOverload<int>::of(&QSpinBox::valueChanged),
                this, &Window::radiusChanged);
    connect(axisXQSpinBox, QOverload<int>::of(&QSpinBox::valueChanged),
                this, &Window::changeAxisX);
    connect(axisYQSpinBox, QOverload<int>::of(&QSpinBox::valueChanged),
                this, &Window::changeAxisY);

    QLabel *labelRender= new QLabel(tr("Draw Area"));

    QGridLayout *mainLayout = new QGridLayout;

    mainLayout->setColumnStretch(0, 1);
    mainLayout->setColumnStretch(3, 1);
    mainLayout->addWidget(labelRender, 1, 0, 0, 0);
    mainLayout->addWidget(renderArea, 0, 0, 1, 4);

    mainLayout->addWidget(radiusLabel, 2, 0, Qt::AlignLeft);
    mainLayout->addWidget(radiusQSpinBox, 2, 1);

    mainLayout->addWidget(axisXQSpinBoxLabel, 3, 0, Qt::AlignLeft);
    mainLayout->addWidget(axisXQSpinBox, 3, 1);

    mainLayout->addWidget(axisYQSpinBoxLabel, 4, 0, Qt::AlignLeft);
    mainLayout->addWidget(axisYQSpinBox, 4, 1);

    setLayout(mainLayout);


    setWindowTitle(tr("Lab 2"));
}

void Window::radiusChanged()
{
    renderArea->radius = radiusQSpinBox->value();
    renderArea->update();
}

void Window::changeAxisX(){
    renderArea->axisX = axisXQSpinBox->value();
    renderArea->update();
}

void Window::changeAxisY(){
    renderArea->axisY = axisYQSpinBox->value();
    renderArea->update();
}

