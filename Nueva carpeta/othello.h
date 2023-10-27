using namespace std;
#include <iostream>
#ifndef OTHELLO_H
#define OTHELLO_H
#include "othello.h"


class othello
{
private:
    char** tablero;
    int tamaño_tablero;
    int pos_x,pos_y;

public:

    othello(int tamaño);
    void imprimir_tablero();
    void imprimir_fut_pos_x();
    void recibe_ficha_x();
    void imprimir_fut_pos_y();
    void recibe_ficha_y();
    void imprimir_error_en_posicion();

};

#endif // OTHELLO_H
