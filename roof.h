#ifndef ROOF_H
#define ROOF_H
#include <QTimer>
#include <QPainter>
#include <QRandomGenerator>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>


class Roof
{

private:

    QImage roof;

    int m; //координата появления крыши по Х
    int n; //координата появления крыши по Y

    int x; //координата движения крыши


public:
    Roof();
    Roof(int);
    ~Roof() {};
    Roof(Roof&);

   QImage getImage();
   int getX();
   void setX(int);
   int getY();
   int getAbsoluteX();

   Roof& operator= (const Roof &roof)
   {
                // Выполняем копирование значений
                this->m = roof.m;
                this->n = roof.n;
                this->x=roof.x;


                return *this;
     }

};


#endif // ROOF_H
