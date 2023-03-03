#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QGridLayout>
#include <QPaintDevice>
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>
#include <QTimerEvent>
#include <QMouseEvent>
#include <QLabel>
#include <QLineEdit>
#include <QLayout>
#include <QGraphicsScene>
#include <QComboBox>
#include <QFile>
#include <QMultiMap>
#include "character.h"
#include "roof.h"
#include "snowflake.h"

typedef QMultiMap<int, QString> map;

class MainWindow : public QWidget
{
    Q_OBJECT

private:

    //для геймплея

    Character ch; //объект персонаж
    Snowflake* snowflake; //снежинки, которые нужно собрать
    Roof* rf; //массив из крыш
    int num; //размер массива крыш
    int num2; //размер массива снежинок
    bool Up; //движение вверх или вниз
    bool isActive; //игра активна или нет
    int counter;  //количество собранных снежинок
    float speed;

    QTimer* timerJump; //таймер для прыжка
    QTimer* timerRoofs; //таймер для движения фона

     //для меню

    QGridLayout* layout;
    QPushButton* pcmdA;
    QPushButton* pcmdB;
    QString name;
    QLineEdit* ptxt;
    QComboBox* cbo;
    QLabel* plbl1;
    QLabel* plbl2;
    QLabel* plbl;
    QLabel* plbl3;


public:

    MainWindow(QWidget* pobj = 0);
    ~MainWindow();

    void window();
    void makeRoof();
    void makeCharacter();
    void makeSnowflake();
    void drawRoof(QPainter&);
    void drawCharacter(QPainter&);
    void drawBackground(QPainter&);
    void drawSnowflake(QPainter&);
    void drawCounterText(QPainter&);
    void moveSnowflake();
    void moveRoof();
    void moveCharacter();
    void File();


public slots:

    void startingGame();
    void OnTimerJump(); //слот для работы с таймером
    void OnTimerRoofs(); //слот для работы с таймером
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);
    void mousePressEvent(QMouseEvent *event);
    void checkCollisionUp();
    void checkCollisionLeft();
    void checkCollect();
    void gameStop();
    void exit();
    void returnGameMenu();

signals:
    void exitApp();


};
#endif




