#include <iostream>
#include <ctime>
#include <sstream>
#include "othello.h"

using namespace std;

int main()
{   //int pos_x,pos_y;
    bool c = true, u= true,v = true, turnw = true, turnb = true;
    othello game(8);

    //Funciones ingresar nombres de los jugadores

    while (c)
    {
        //bool turnw = game.P_Posibilidad_jugada('-','*');
        if(turnw)
        {
         game.imprimir_tablero();
          while(u)
          {
           cout<<"turno blanco"<<endl;
           game.recibe_ficha_x();
           game.recibe_ficha_y();
           u = game.P_Validar_pos('-','*');
          }
          game.actualizar_tablero('*');
          game.voltear_fichas('*', '-');
          game.imprimir_tablero();
        }

        //bool turnb = game.P_Posibilidad_jugada('*','-');
        if(turnb)
        {
          while(v)
          {
           cout<<"turno negro"<<endl;
           game.recibe_ficha_x();
           game.recibe_ficha_y();
           v = game.P_Validar_pos('*','-');
          }
          game.actualizar_tablero('-');
          game.voltear_fichas('-', '*');
        }
/*
        if((!turnw)&&(!turnb))
        {
          //funcion terminar juego y dar la opcion de ver el historico de las partidas
        }*/
    }


    return 0;
}
