#include <iostream>

#include "othello.h"

using namespace std;

int main()
{   int pos_x,pos_y;
    othello hola(8);

    hola.imprimir_tablero();
    hola.imprimir_fut_pos_x();
    cin>>pos_x;
    hola.recibe_ficha_x(pos_x);
    hola.imprimir_fut_pos_y();
    cin>>pos_y;
    hola.recibe_ficha_y(pos_y);
    hola. actualizar_tablero('*');
    hola.imprimir_tablero();


    return 0;
}
