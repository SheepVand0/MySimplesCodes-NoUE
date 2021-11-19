#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <iostream>

using namespace std;

void MainWindow::OnGenerateClick() {

    int returnvalue = getRandomNumber(MinNum->value(), MaxNum->value());
    MainWindow::ReturnNumber->setText(QString::number(returnvalue));
    cout << returnvalue << endl;

}

int MainWindow::getRandomNumber(int min, int max) {
    return (rand() %  ((max + 1) - min) + min);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //ui->setupUi(this);

    centralwidget = new QWidget(this);
    centralwidget->setObjectName(QStringLiteral("centralwidget"));
    widget = new QWidget(centralwidget);
    widget->setObjectName(QStringLiteral("widget"));
    widget->setGeometry(QRect(0, 10, 791, 211));
    QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    sizePolicy.setHorizontalStretch(100);
    sizePolicy.setVerticalStretch(100);
    sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
    widget->setSizePolicy(sizePolicy);
    ReturnNumber = new QLabel(widget);
    ReturnNumber->setObjectName(QStringLiteral("ReturnNumber"));
    ReturnNumber->setGeometry(QRect(0, 0, 301, 151));
    QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(ReturnNumber->sizePolicy().hasHeightForWidth());
    ReturnNumber->setSizePolicy(sizePolicy1);
    QFont font;
    font.setFamily(QStringLiteral("Segoe UI"));
    font.setPointSize(22);
    font.setBold(true);
    font.setWeight(75);
    ReturnNumber->setFont(font);
    Generate = new QPushButton(widget);
    Generate->setObjectName(QStringLiteral("Generate"));
    Generate->setGeometry(QRect(0, 164, 771, 41));
    Generate->setText("Generate Random Number");
    MinNum = new QSpinBox(widget);
    MinNum->setObjectName(QStringLiteral("MinNum"));
    MinNum->setGeometry(QRect(320, 40, 91, 101));
    MinNum->setMinimum(0);
    QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Maximum);
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(MinNum->sizePolicy().hasHeightForWidth());
    MinNum->setSizePolicy(sizePolicy2);
    MaxNum = new QSpinBox(widget);
    MaxNum->setObjectName(QStringLiteral("MaxNum"));
    MaxNum->setGeometry(QRect(540, 40, 91, 111));
    MaxNum->setMinimum(1);
    sizePolicy2.setHeightForWidth(MaxNum->sizePolicy().hasHeightForWidth());
    MaxNum->setSizePolicy(sizePolicy2);
    label = new QLabel(widget);
    label->setObjectName(QStringLiteral("label"));
    label->setGeometry(QRect(320, 0, 81, 41));
    label->setText(QString("Min Number"));
    label_2 = new QLabel(widget);
    label_2->setObjectName(QStringLiteral("label_2"));
    label_2->setGeometry(QRect(540, 0, 101, 41));
    label_2->setText(QString("Max Number"));
    setCentralWidget(centralwidget);
    menubar = new QMenuBar(this);
    menubar->setObjectName(QStringLiteral("menubar"));
    menubar->setGeometry(QRect(0, 0, 800, 25));
    setMenuBar(menubar);
    statusbar = new QStatusBar(this);
    statusbar->setObjectName(QStringLiteral("statusbar"));
    setStatusBar(statusbar);

    this->resize(800, 350);

    QObject::connect(Generate, SIGNAL(clicked()), this, SLOT(OnGenerateClick()));
}

MainWindow::~MainWindow()
{

}

