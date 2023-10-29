#include <iostream>

#include "othello.h"

using namespace std;

int main()
{   //int pos_x,pos_y;
    othello hola(8);

    hola.imprimir_tablero();

    hola.recibe_ficha_x(8);
    hola.recibe_ficha_y(1);
    hola. actualizar_tablero('*');
    hola.recibe_ficha_x(7);
    hola.recibe_ficha_y(8);
    hola. actualizar_tablero('*');
    hola.recibe_ficha_x(1);
    hola.recibe_ficha_y(5);
    hola. actualizar_tablero('*');
    hola.recibe_ficha_x(1);
    hola.recibe_ficha_y(2);
    hola. actualizar_tablero('*');
    hola.recibe_ficha_x(1);
    hola.recibe_ficha_y(8);
    hola. actualizar_tablero('-');
    hola.recibe_ficha_x(8);
    hola.recibe_ficha_y(5);
    hola. actualizar_tablero('*');
    hola.recibe_ficha_x(4);
    hola.recibe_ficha_y(1);
    hola. actualizar_tablero('*');
    hola.recibe_ficha_x(4);
    hola.recibe_ficha_y(8);
    hola. actualizar_tablero('*');

    hola.recibe_ficha_x(2);
    hola.recibe_ficha_y(5);
    hola. actualizar_tablero('-');
    hola.recibe_ficha_x(3);
    hola.recibe_ficha_y(5);
    hola. actualizar_tablero('-');

    hola.recibe_ficha_x(4);
    hola.recibe_ficha_y(4);
    hola. actualizar_tablero('-');
    hola.recibe_ficha_x(4);
    hola.recibe_ficha_y(3);
    hola. actualizar_tablero('-');
    hola.recibe_ficha_x(4);
    hola.recibe_ficha_y(2);
    hola. actualizar_tablero('-');

    hola.recibe_ficha_x(4);
    hola.recibe_ficha_y(6);
    hola. actualizar_tablero('-');
    hola.recibe_ficha_x(4);
    hola.recibe_ficha_y(7);
    hola. actualizar_tablero('-');

    hola.recibe_ficha_x(2);
    hola.recibe_ficha_y(3);
    hola. actualizar_tablero('-');
    hola.recibe_ficha_x(3);
    hola.recibe_ficha_y(4);
    hola. actualizar_tablero('-');

    hola.recibe_ficha_x(3);
    hola.recibe_ficha_y(6);
    hola. actualizar_tablero('-');
    hola.recibe_ficha_x(2);
    hola.recibe_ficha_y(7);
    hola. actualizar_tablero('-');

    hola.recibe_ficha_x(5);
    hola.recibe_ficha_y(6);
    hola. actualizar_tablero('-');
    hola.recibe_ficha_x(6);
    hola.recibe_ficha_y(7);
    hola. actualizar_tablero('-');

    hola.recibe_ficha_x(8);
    hola.recibe_ficha_y(8);
    hola. actualizar_tablero('-');
    hola.recibe_ficha_x(7);
    hola.recibe_ficha_y(2);
    hola. actualizar_tablero('-');



    hola.recibe_ficha_x(7);
    hola.recibe_ficha_y(2);
    hola. actualizar_tablero('*');
    //hola.voltear_fichas('*','-');
    hola.imprimir_tablero();


    return 0;
}
