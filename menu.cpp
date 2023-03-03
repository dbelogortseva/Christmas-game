#include "menu.h"

Menu::Menu(QWidget* pwgt) : QWidget(pwgt)
{
    window();
}

Menu::~Menu()
{

}



void Menu::window()
{
    //параметры главного окна
    resize(500, 400); //задаем размер окна
    setWindowTitle("My Game");

    //оформление курсора
    QPixmap pix("D:/QT_works/kursovaya/cursor.png");
    QCursor cursor(pix);
    setCursor(cursor);


    //ввод имени и выбор уровня сложности

    QLabel* plblText = new QLabel("&Введите ваше имя:");
    QLineEdit* ptxt = new QLineEdit;
    plblText->setBuddy(ptxt);

    lvl1 = new QPushButton("Легкий");
    connect(lvl1, SIGNAL(clicked()), SLOT(level1));

    lvl2 = new QPushButton("Средний");
    connect(lvl2, SIGNAL(clicked()), SLOT(level2));

    lvl3 = new QPushButton("Сложный");
    connect(lvl3, SIGNAL(clicked()), SLOT(level3));

    //Layout
    lay = new QVBoxLayout;
    lay->addWidget(plblText);
    lay->addWidget(ptxt);
    lay->addWidget(lvl1);
    lay->addWidget(lvl2);
    lay->addWidget(lvl3);
    setLayout(lay);
}


void Menu::level1()
{
  int speed = 1;
  MainWindow a(speed);

  a.show();
}

void Menu::level2()
{
  int speed = 2;
  MainWindow a(speed);
  a.show();
}

void Menu::level3()
{
    int speed = 3;
    MainWindow a(speed);
    a.show();
}


