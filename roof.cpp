#include "roof.h"

Roof::Roof() : m(500), n(265)
{
    int value;

    this->x = m;


    QImage roofOrig1("D:/QT_works/kursovaya/roof11.png");
    QImage roofOrig2("D:/QT_works/kursovaya/roof2.png");
    QImage roofOrig3("D:/QT_works/kursovaya/roof3.png");
    QImage roofOrig4("D:/QT_works/kursovaya/roof4.png");


    value = QRandomGenerator::global()->bounded(0, 3);

    if (value == 0) this->roof = roofOrig1.scaled(160,136);
    if (value == 1) this->roof = roofOrig2.scaled(160,136);
    if (value == 2) this->roof = roofOrig3.scaled(160,136);
    if (value == 3) this->roof = roofOrig4.scaled(160,136);


}

Roof::Roof(int i) : m(500), n(265)
{
    int value;

    this->x = (i+0.5)*160 + 10*i  ;

    QImage roofOrig1("D:/QT_works/kursovaya/roof1.png");
    QImage roofOrig2("D:/QT_works/kursovaya/roof2.png");

    srand(time(NULL));
    value = QRandomGenerator::global()->bounded(0, 2);
    if (value == 0) this->roof = roofOrig1.scaled(160,136);
    if (value == 1) this->roof = roofOrig2.scaled(160,136);
    if (value == 2) this->roof = roofOrig1.scaled(160,136);

}

Roof::Roof (Roof& rf): roof(rf.roof), m(rf.m), n(rf.n),  x(rf.x)

{
    //конструктор копирования
}

QImage Roof::getImage()
{
    return this->roof;
}


int Roof::getX()
{
    return this->x;
}

void Roof::setX(int x)
{
  this->x = x;
}

int Roof::getY()
{
    return this->n;
}

int Roof::getAbsoluteX()
{
    return this->m;
}

