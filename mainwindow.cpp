#include "mainwindow.h"
//#include "ui_mainwindow.h"
#include <QWidget>

//конструкторы и деструкторы

MainWindow::MainWindow(QWidget* pwgt)
  : QWidget(pwgt), num(4), num2(6)
{
    isActive = 0;
    window();
}

MainWindow::~MainWindow()
{

}



//дизайн окна
void MainWindow::window()
{
    //параметры главного окна
    resize(500, 400); //задаем размер окна
    setWindowTitle("My Game");

    //оформление курсора
    QPixmap pix("D:/QT_works/kursovaya/cursor.png");
    QCursor cursor(pix);
    setCursor(cursor);

    //ввод имени
    ptxt = new QLineEdit;
    plbl1= new QLabel("Введите имя");

    //выбор сложности
    plbl2= new QLabel("Выберите уровень сложности");
    cbo = new QComboBox;
    QStringList lst;
    lst << "Низкий" << "Средний" << "Сложный";
    cbo->addItems(lst);
    cbo->setEditable(false);

    //кнопки
    pcmdA = new QPushButton("Начать игру");
    connect(pcmdA, SIGNAL(clicked()), SLOT(startingGame()));

    pcmdB = new QPushButton("Выйти");
    connect(pcmdB, SIGNAL(clicked()), SLOT(exit()));

    plbl = new QLabel;
    plbl3 = new QLabel;

    //Layout
    layout = new QGridLayout;
    layout->addWidget(plbl1, 0, 0);
    layout->addWidget(ptxt, 0, 1);

    layout->addWidget(plbl2, 1, 0);
    layout->addWidget(cbo, 1, 1);

    layout->addWidget(pcmdA, 2, 1);
    layout->addWidget(pcmdB, 3, 1);
    setLayout(layout);

}


void MainWindow::startingGame()
{
    //сохраняем инфу из диалогового окна
    if (cbo->currentText() == "Низкий") speed = 1.3;
    if (cbo->currentText() == "Средний") speed = 1;
    if (cbo->currentText() == "Сложный") speed = 0.7;
    name = ptxt->text();

    //удаляем виджеты, чтобы сменить сцену и начать игру
    delete pcmdA;
    delete pcmdB;
    delete layout;
    delete cbo;
    delete ptxt;
    delete plbl1;
    delete plbl2;
    delete plbl;
    delete plbl3;

    //делаем игру активной и создаем и обновляем объекты
    counter = 0;
    makeRoof();
    makeCharacter();
    makeSnowflake();
    isActive = 1;
    update();
}

void MainWindow::returnGameMenu()
{
    //обновляем информацию
    isActive = 0;
    delete timerRoofs;
    delete timerJump;
    delete [] rf;
    delete [] snowflake;
    update();


    QFont f( "FuturaFuturisC", 20, QFont::Bold);

     QString str;
     str.setNum(counter);
     plbl= new QLabel("Ваш результат:");
     plbl->setFont(f);
     plbl3= new QLabel(str);
     plbl3->setFont(f);


    //новое меню с предложением вернуться


     //ввод имени
     ptxt = new QLineEdit;
     plbl1= new QLabel("Введите имя");

     //выбор сложности
     plbl2= new QLabel("Выберите сложность");
     cbo = new QComboBox;
     QStringList lst;
     lst << "Низкий" << "Средний" << "Сложный";
     cbo->addItems(lst);
     cbo->setEditable(false);

    pcmdA = new QPushButton("Попробовать ещё раз!");
    connect(pcmdA, SIGNAL(clicked()), SLOT(startingGame()));

    pcmdB = new QPushButton("Выйти");
    connect(pcmdB, SIGNAL(clicked()), SLOT(exit()));

    layout = new QGridLayout;
    layout->addWidget(plbl, 0, 1, Qt::AlignLeft);
    layout->addWidget(plbl3, 1, 1, Qt::AlignLeft);

    layout->addWidget(plbl1, 2, 0);
    layout->addWidget(ptxt, 2, 1);

    layout->addWidget(plbl2, 3, 0);
    layout->addWidget(cbo, 3, 1);

    layout->addWidget(pcmdA, 4, 1);
    layout->addWidget(pcmdB, 5, 1);
    setLayout(layout);

}

 void MainWindow::gameStop()
{
    timerRoofs->stop();
    timerJump->stop();
    //File();
    QTimer::singleShot(1000*1.5, this, SLOT(returnGameMenu()));
 }

 void MainWindow::exit()
 {
     emit exitApp();
 }

//создание объектов
void MainWindow::makeRoof()
{
    rf = new Roof [num];
    for (int i = 0; i< num; i++)
    {
        Roof a(i);
        rf[i]=a;
    }

    //таймер движения крыши и снежинок
    timerRoofs = new QTimer(this);
    connect(timerRoofs, SIGNAL(timeout()), this, SLOT(OnTimerRoofs()));
    timerRoofs->start(19*speed);
}

void MainWindow::makeCharacter()
{
    ch.setY(258); //возвращаем в исходную позицию
    //таймер прыжка вверх
    timerJump = new QTimer(this);
    connect(timerJump, SIGNAL(timeout()), this, SLOT(OnTimerJump()));
}

void MainWindow::makeSnowflake()
{
    snowflake = new Snowflake [num2];

    for (int i = 0; i< num2; i++)
    {
        Snowflake b(i);
        snowflake[i] = b;
    }

    counter = 0;
}




//прорисовка сцен и объектов
void MainWindow::paintEvent(QPaintEvent *event)
{
    if (isActive)
    {
    QPainter painter(this);
    drawBackground(painter);
    drawCharacter(painter);
    drawSnowflake(painter);
    drawRoof(painter);

    //количество очков (символ)
    QImage counter("D:/QT_works/kursovaya/snowflake.png");
    counter = counter.scaled(25, 25);
    painter.drawImage(10, 10, counter);
    drawCounterText(painter);
    }


}


void MainWindow::drawCharacter(QPainter &painter)
{
    painter.drawImage(ch.getX(), ch.getY(), ch.getImage());
}

void MainWindow::drawBackground(QPainter &painter)
{
    QImage back("D:/QT_works/kursovaya/background.png");
    painter.drawImage(0, 0, back);
}

void MainWindow::drawSnowflake(QPainter &painter)
{
    for (int i = 0; i<num2; ++i)
    {
    painter.drawImage(snowflake[i].getX(), snowflake[i].getY(), snowflake[i].getImage());
    }

}

void MainWindow::drawCounterText(QPainter &painter)
{
    QString counterText;
    QFont serifFont("FuturaFuturisC", 20, QFont::Bold);
    painter.setFont(serifFont);

    counterText.setNum(counter);

    painter.drawText(50, 40, counterText);
}

void MainWindow::drawRoof(QPainter &painter)
{
    for (int i = 0; i<num; ++i)
    {
    painter.drawImage(rf[i].getX(), rf[i].getY(), rf[i].getImage());
    }
}




//движение объектов

void MainWindow::moveSnowflake()
{
    QPainter painter(this);

    for (int i = 0; i < num2; ++i)
    {

        if (snowflake[i].getX() >= -50)
        {
            snowflake[i].setX(snowflake[i].getX() - 5);
        }
        else snowflake[i].setX(530);
    }

     update();
}

void MainWindow::moveCharacter()
{
    QPainter painter(this);

    if (ch.getY()>100 && Up)
    {
        ch.setY( ch.getY() - 2);
       update();

        if (ch.getY()==100) Up = 0; //движение вверх закончилось
    }

    if (ch.getY()<258 && !Up) //началось движение вверх
    {
        ch.setY( ch.getY() + 2);
        update();

        if (ch.getY()==258)
        {
            Up = 1;
            timerJump->stop();
        }
    }
}

void MainWindow::moveRoof()
{
    QPainter painter(this);
    for (int i = 0; i < num; ++i)
    {

        if (rf[i].getX() >= -180)
        {
            rf[i].setX(rf[i].getX() - 5);
        }
        else rf[i].setX(rf[i].getAbsoluteX());
    }
   update();

}





//реагирование на кнопки и мышь
void MainWindow::keyPressEvent(QKeyEvent *pe)
{

    if (((pe->key() == Qt::Key_Space || pe->key() == Qt::Key_Up))&& isActive)
    {
       Up = 1;
       timerJump->start(speed);
    }
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
   if((e->button() == Qt::LeftButton) && isActive)
   {
       Up = 1;
       timerJump->start(speed);
   }
}




//взаимодействия между объектами
void MainWindow::checkCollisionUp()
{
    for (int i = 0; i<num; ++i)
    {
       if ( ((ch.getY() + 70) == 272) && ((rf[i].getX()+160) >= 10) && ((rf[i].getX()+112) <= 75 )  )
           emit gameStop();
    }
}

void MainWindow::checkCollisionLeft()
{
    for (int i = 0; i<num; ++i)
    {
        if ( ((ch.getX() + 70) == (rf[i].getX()+135)) && ((ch.getY() == 258 )) )
            emit gameStop();
    }
}

void MainWindow::checkCollect()
{

    for (int i = 0; i<num2; ++i)
    {
        if ( ((snowflake[i].getX() + 30) >= 10) && ((snowflake[i].getX() + 30) <= 50) && (ch.getY() <= (snowflake[i].getY()+30))  )
        {
            ++counter;
            snowflake[i].setX(530);
            update();
        }
    }

}






//работа с таймером
void MainWindow::OnTimerJump()
{
    moveCharacter();
    emit checkCollisionUp();
    emit checkCollect();
}

void MainWindow::OnTimerRoofs()
{
    moveRoof();
    moveSnowflake();

    emit checkCollisionLeft();
}


void MainWindow::File()
{
    map rating;

    QFile fin("D:/QT_works/kursovaya/file.txt");
        fin.open(QIODevice::ReadOnly);

    QString string;
    QString text;
    int points;
    QStringList stringList;

    if (name == "") name = "Guest";

        while (!fin.atEnd()) //считываем данные из файла, пока не дойдем до конца файла
        {
            //извлекаем информацию
            string = fin.readLine();
            stringList = string.split(" ");
            text = stringList[0];
            points = stringList[1].toInt();
            rating.insert(points, text);
        }

         fin.close();

         rating.insert(counter, name);

         QFile file("D:/QT_works/kursovaya/file.txt");
         file.open(QIODevice::WriteOnly);
         QTextStream out(&file);

         map::iterator it = rating.end();
         it--;

         int size = 5;

         if (rating.size()<size)
         size = rating.size();

         for (int i = 0; i < size; i++)
         {
         out << it.value() << " " << it.key() << "\n";
         it--;
         }

         file.close();
}

