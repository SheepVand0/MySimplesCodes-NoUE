#include "randomfromlist.h"
#include "ui_randomfromlist.h"
#include <cstdlib>
#include <iostream>

using namespace std;

void RandomFromList::addItem() {

    cout << "Added" << endl;

    ElementsList->addItem(NewElementText->text());

}

QString RandomFromList::getRandomItemFromList() {

        return ElementsList->takeItem(rand() % ElementsList->currentRow() + 1)->text();

}

void RandomFromList::OnGenerateClick() {
    QString value = ElementsList->takeItem(rand() % (ElementsList->children().count() - 1) + 1)->text();
    ReturnedValue->setText(value);
    ElementsList->addItem(value);

}

void RandomFromList::RemoveSelectedElement() {
    cout << "Works" << endl;
    QList<QListWidgetItem*> items = ElementsList->selectedItems();
    if (items.at(0) != Q_NULLPTR) {
        delete items.at(0);
    }
}

RandomFromList::RandomFromList(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RandomFromList)
{
    this->resize(800, 600);
    centralwidget = new QWidget(this);
    centralwidget->setObjectName(QStringLiteral("centralwidget"));
    ElementsList = new QListWidget(centralwidget);
    ElementsList->setObjectName(QStringLiteral("ElementsList"));
    ElementsList->setGeometry(QRect(440, 180, 351, 291));
    ElementsList->setProperty("showDropIndicator", QVariant(false));
    AddElementtolist = new QPushButton(centralwidget);
    AddElementtolist->setObjectName(QStringLiteral("AddElementtolist"));
    AddElementtolist->setGeometry(QRect(670, 130, 121, 41));
    DeleteSelectedElement = new QPushButton(centralwidget);
    DeleteSelectedElement->setObjectName(QStringLiteral("DeleteSelectedElement"));
    DeleteSelectedElement->setGeometry(QRect(439, 480, 351, 51));
    NewElementText = new QLineEdit(centralwidget);
    NewElementText->setObjectName(QStringLiteral("NewElementText"));
    NewElementText->setGeometry(QRect(440, 130, 221, 41));
    NewElementText->setInputMethodHints(Qt::ImhNone);
    ReturnedValue = new QLabel(centralwidget);
    ReturnedValue->setObjectName(QStringLiteral("ReturnedValue"));
    ReturnedValue->setGeometry(QRect(10, 10, 161, 161));
    QFont font;
    font.setFamily(QStringLiteral("Segoe UI"));
    font.setPointSize(14);
    font.setBold(true);
    font.setItalic(true);
    font.setWeight(75);
    ReturnedValue->setFont(font);
    ReturnedValue->setInputMethodHints(Qt::ImhPreferUppercase|Qt::ImhUppercaseOnly);
    Generate = new QPushButton(centralwidget);
    Generate->setObjectName(QStringLiteral("Generate"));
    Generate->setGeometry(QRect(0, 310, 431, 61));
    this->setCentralWidget(centralwidget);
    menubar = new QMenuBar(this);
    menubar->setObjectName(QStringLiteral("menubar"));
    menubar->setGeometry(QRect(0, 0, 800, 25));
    this->setMenuBar(menubar);
    statusbar = new QStatusBar(this);
    statusbar->setObjectName(QStringLiteral("statusbar"));
    this->setStatusBar(statusbar);

    this->setWindowTitle(QApplication::translate("RandomFromList", "MainWindow", Q_NULLPTR));
    AddElementtolist->setText(QApplication::translate("RandomFromList", "Add item", Q_NULLPTR));
    DeleteSelectedElement->setText(QApplication::translate("RandomFromList", "Remove Selected Item", Q_NULLPTR));
    ReturnedValue->setText(QApplication::translate("RandomFromList", "TextLabel", Q_NULLPTR));
    Generate->setText(QApplication::translate("RandomFromList", "Generate", Q_NULLPTR));

    connect(AddElementtolist,SIGNAL(clicked()),this,SLOT(addItem()));
    connect(DeleteSelectedElement,SIGNAL(clicked()),this,SLOT(RemoveSelectedElement()));
    connect(Generate,SIGNAL(clicked()),this,SLOT(OnGenerateClick()));
}

RandomFromList::~RandomFromList()
{
    delete ui;
}
