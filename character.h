#ifndef CHARACTER_H
#define CHARACTER_H
#include <QObject>
#include <QImage>

class Character : public QObject
{
    Q_OBJECT

private:

    QImage character;
    const int x;
    int y;



public:
    Character();
    ~Character() {};
   QImage getImage();
   int getX();
   int getY();
   void setY(int);


};


#endif // CHARACTER_H
