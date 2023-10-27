#include <iostream>

#include "othello.h"

using namespace std;

int main()
{
    othello hola(8);

    hola.imprimir_tablero();
    hola.imprimir_fut_pos_x();
    hola.recibe_ficha_x();
    hola.imprimir_fut_pos_y();
    hola.recibe_ficha_y();
    hola.imprimir_tablero();


    return 0;
}
