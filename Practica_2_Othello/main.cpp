#include <iostream>
#include <ctime>
#include <sstream>
#include "othello.h"

using namespace std;

int main()
{   int pos_x,pos_y;
    bool c = true;
    othello game(8);

    //Funcione ingresar nombres de los jugadores
    game.imprimir_tablero();

    while (c)
    {
      game.recibe_ficha_x();
      game.recibe_ficha_y();
    }
      /*
      game.P_Posibilidad_jugada();//if
      //game.P_Validar_pos(pos_x,pos_y);
      game.actualizar_tablero('*');
      game.voltear_fichas('*', '-');
      */






    return 0;
}
