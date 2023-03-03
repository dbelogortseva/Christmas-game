#include "snowflake.h"

Snowflake::Snowflake()
{
    QImage imageOrig("D:/QT_works/kursovaya/snowflake.png");
    this->image = imageOrig.scaled(30, 30);

    this->x=0;
    this->y = QRandomGenerator::global()->bounded(130, 230);;

}

Snowflake::Snowflake(int i)
{
    QImage imageOrig("D:/QT_works/kursovaya/snowflake.png");

    this->image = imageOrig.scaled(30, 30);

    this->x = (i+0.5)*100 + 10*i;
    this->y = QRandomGenerator::global()->bounded(140, 230);
}


Snowflake::Snowflake(Snowflake &snow) : image(snow.image), x(snow.x), y(snow.y)
{
    //конструктор копирования
}

QImage Snowflake::getImage()
{
    return this->image;
}

int Snowflake::getX()
{
    return this->x;
}

void Snowflake::setX(int x)
{
    this->x=x;
}

int Snowflake::getY()
{
    return this->y;
}

Snowflake& Snowflake:: operator= (const Snowflake &snow)
{
            this->image = snow.image;
             this->x = snow.x;
             this->y = snow.y;

             return *this;
}
