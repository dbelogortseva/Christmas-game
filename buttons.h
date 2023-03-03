#ifndef BUTTONS_H
#define BUTTONS_H

#include <QPushButton>

class Buttons : QWidget
{
private:
    QPushButton cmd;
public:

    Buttons(QString);

public slots:
    void startGame();
    void viewResults();
    void returnBack();
};

#endif // BUTTONS_H
