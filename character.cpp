#include "character.h"


Character::Character() : x(10)
{
    this->y = 258;
    QImage characterOrig("D:/QT_works/kursovaya/dedmoroz.png");
    this->character = characterOrig.scaled(70, 70);

}

QImage Character::getImage()
{
    return this->character;
}

int Character::getX()
{
    return this->x;
}

void Character::setY(int y)
{
  this->y = y;
}

int Character::getY()
{
    return this->y;
}

