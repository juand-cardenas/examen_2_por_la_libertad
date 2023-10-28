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
    bool verificacion=true;

public:

    othello(int tamaño);
    void imprimir_tablero();
    void imprimir_fut_pos_x();
    void recibe_ficha_x(int posx);
    void imprimir_fut_pos_y();
    void recibe_ficha_y(int posy);
    void imprimir_error_en_posicion();
    void actualizar_tablero(char ficha);
    void voltear_fichas(char ficha_alidad, char ficha_enemiga);

};

#endif // OTHELLO_H
