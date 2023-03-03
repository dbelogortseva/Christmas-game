#ifndef MENU_H
#define MENU_H
#include <QPushButton>
#include <QString>

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <buttons.h>
#include <QPaintDevice>
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>
#include <QTimerEvent>
#include <QMouseEvent>
#include <QLabel>
#include <QLineEdit>
#include "character.h"
#include "roof.h"
#include "snowflake.h"
#include "mainwindow.h"


class Menu : public QWidget
{
     Q_OBJECT

private:
QVBoxLayout* lay;
QLineEdit* ptxt;
QPushButton* start;
QPushButton* cont;
QPushButton* lvl1;
QPushButton* lvl2;
QPushButton* lvl3;
QString name;
int speedCh;
int speedRf;

public:
    Menu(QWidget* pobj = 0);
    ~Menu();
    void window();


public slots:
    void level1();
    void level2();
    void level3();

};

#endif // MENU_H
