#include <iostream>
#include <ctime>
#include <sstream>
#include "othello.h"
#include<string.h>
#include <bitset>
#include <fstream>

using namespace std;

int main()
{   //int pos_x,pos_y;
    othello tablero(8);


   /* cout<<tablero.Posibilidad_jugada(char '*');
    if(tablero.Posibilidad_jugada(char '*')){
        tablero.imprimir_tablero();
        tablero.posicion_valida=false;
        while(!tablero.Validar_pos()){
            while (!tablero.posicion_valida) {
                tablero.recibe_ficha_x();
            }
            tablero.posicion_valida=false;
            while (!tablero.posicion_valida) {
                tablero.recibe_ficha_y();
            }

            if(tablero.Validar_pos()){
                tablero.actualizar_tablero('*');
                tablero.voltear_fichas('*','-');
            }
            tablero.imprimir_tablero();
        }
    }

    tablero.Posibilidad_jugada(char '-');
    if(tablero.Posibilidad_jugada(char '-')){
        tablero.imprimir_tablero();
        tablero.posicion_valida=false;
        while (!tablero.posicion_valida) {
            tablero.recibe_ficha_x();
        }
        tablero.posicion_valida=false;
        while (!tablero.posicion_valida) {
            tablero.recibe_ficha_y();
        }

        if(tablero.Validar_pos()){
            tablero.actualizar_tablero('*');
            tablero.voltear_fichas('*','-');

        }
        tablero.imprimir_tablero();

    }

    if(!tablero.Posibilidad_jugada(char '*') and !tablero.Posibilidad_jugada(char '-')){

    }*/



    //tablero.tiempo();
    tablero.monstrar_el_registro();





    /*tablero.posicion_valida=false;
    while (!tablero.posicion_valida) {
        tablero.recibe_ficha_x();
    }
    tablero.posicion_valida=false;
    while (!tablero.posicion_valida) {
        tablero.recibe_ficha_y();
    }*/

    return 0;
}
