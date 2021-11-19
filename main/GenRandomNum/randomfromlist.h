#ifndef RANDOMFROMLIST_H
#define RANDOMFROMLIST_H

#include <QMainWindow>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

namespace Ui {
class RandomFromList;
}

class RandomFromList : public QMainWindow
{
    Q_OBJECT

public:
    explicit RandomFromList(QWidget *parent = nullptr);
    ~RandomFromList();

    QWidget *centralwidget;
    QListWidget *ElementsList;
    QPushButton *AddElementtolist;
    QPushButton *DeleteSelectedElement;
    QLineEdit *NewElementText;
    QLabel *ReturnedValue;
    QPushButton *Generate;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    QString items[0] = {};

public slots:

    void addItem();
    QString getRandomItemFromList();
    void OnGenerateClick();
    void RemoveSelectedElement();

private:
    Ui::RandomFromList *ui;
};

#endif // RANDOMFROMLIST_H
