#ifndef SNOWFLAKE_H
#define SNOWFLAKE_H

#include <QTimer>
#include <QPainter>
#include <QRandomGenerator>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>


class Snowflake
{

private:

    QImage image;
    int x;
    int y;


public:
    Snowflake();
    Snowflake(int);
    ~Snowflake() {};
    Snowflake(Snowflake&);

   QImage getImage();
   int getX();
   void setX(int);
   int getY();


   Snowflake& operator= (const Snowflake &snowflake);


};

#endif // SNOWFLAKE_H
