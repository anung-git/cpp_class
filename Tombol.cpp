

#include <Arduino.h>

Tombol::Tombol(const int up, const int down, const int menu)
{
    pinMode(up,INPUT_PULLUP);
    pinMode(down,INPUT_PULLUP);
    pinMode(menu,INPUT_PULLUP);
    Tombol::down=down;
    Tombol::up=up;
    Tombol::menu=menu;
}

Tombol::~Tombol()
{
}
