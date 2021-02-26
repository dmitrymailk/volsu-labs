

#include "renderarea.h"
#include "colorlisteditor.h"

#include "window.h"

#include <QtWidgets>

// debug
#include <QTextStream>


//! [0]
const int IdRole = Qt::UserRole;
//QTextStream out(stdout);r
//! [0]

//! [1]
Window::Window()
{
    renderArea = new RenderArea;

    QLabel label("Some", renderArea);

    shapeComboBox = new QComboBox;
    shapeComboBox->addItem(tr("Ellipse"), RenderArea::Ellipse);

    shapeLabel = new QLabel(tr("&Shape:"));
    shapeLabel->setBuddy(shapeComboBox);

    penWidthComboBox = new ColorListEditor;
    penWidthLabel = new QLabel(tr("Pen &Color:"));
    penWidthLabel->setBuddy(penWidthComboBox);

    otherOptionsLabel = new QLabel(tr("Options:"));

    antialiasingCheckBox = new QCheckBox(tr("&Antialiasing"));

    addImageFileButton = new QPushButton(tr("Add image..."));
    saveImageFileButton = new QPushButton(tr("Save image..."));

    connect(shapeComboBox, &QComboBox::activated,
            this, &Window::shapeChanged);
    connect(penWidthComboBox, &QComboBox::activated,
            this, &Window::colorChanged);
    connect(antialiasingCheckBox, &QAbstractButton::toggled,
            renderArea, &RenderArea::setAntialiased);
    connect(addImageFileButton, &QPushButton::clicked,
            renderArea, &RenderArea::setImage);
    connect(saveImageFileButton, &QPushButton::clicked,
            renderArea, &RenderArea::saveImage);

    QLabel *labelRender= new QLabel(tr("Draw Area"));

    QGridLayout *mainLayout = new QGridLayout;

    mainLayout->setColumnStretch(0, 1);
    mainLayout->setColumnStretch(3, 1);
    mainLayout->addWidget(labelRender, 1, 0, 0, 0);
    mainLayout->addWidget(renderArea, 0, 0, 1, 4);
    mainLayout->addWidget(shapeLabel, 2, 0, Qt::AlignLeft);
    mainLayout->addWidget(shapeComboBox, 2, 1);
    mainLayout->addWidget(penWidthLabel, 3, 0, Qt::AlignLeft);
    mainLayout->addWidget(penWidthComboBox, 3, 1);
    mainLayout->addWidget(antialiasingCheckBox, 5, 0, Qt::AlignLeft);
    mainLayout->addWidget(saveImageFileButton, 5, 1, 1, 2, Qt::AlignLeft);
    mainLayout->addWidget(addImageFileButton, 5, 2, 1, 2, Qt::AlignRight);
    setLayout(mainLayout);

    shapeChanged();
    colorChanged();
    antialiasingCheckBox->setChecked(true);

    setWindowTitle(tr("Lab 2"));
}

void Window::colorChanged()
{
    QColor color = qvariant_cast<QColor>(penWidthComboBox->itemData(penWidthComboBox->currentIndex(), Qt::DecorationRole));
    renderArea->setBrush(QBrush(color));
}

void Window::shapeChanged()
{
    RenderArea::Shape shape = RenderArea::Shape(shapeComboBox->itemData(
            shapeComboBox->currentIndex(), IdRole).toInt());
    renderArea->setShape(shape);
}

