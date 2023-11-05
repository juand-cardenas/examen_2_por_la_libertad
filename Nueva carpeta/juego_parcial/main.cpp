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

    //tablero.imprimir_tablero();
    tablero.recibir_nombres();
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

    //tablero.recibe_ficha_x();
    //tablero.recibe_ficha_y();
    //tablero.actualizar_tablero('*');

    //tablero.tiempo();
    //tablero.monstrar_el_registro();
    //tablero.imprimir_tablero();
    //tablero.contar_fichas();
    //tablero.decidir_el_ganador();
    int cant=0;
    while(cant<64){
        cout<<endl<<"turno "<<tablero.nombre_negra<<endl;
        tablero.imprimir_tablero();
        tablero.recibe_ficha_x();
        tablero.recibe_ficha_y();
        tablero.actualizar_tablero('-');
        tablero.voltear_fichas('-','*');

        cout<<endl<<"turno "<<tablero.nombre_blanca<<endl;
        tablero.imprimir_tablero();
        tablero.recibe_ficha_x();
        tablero.recibe_ficha_y();
        tablero.actualizar_tablero('*');
        tablero.voltear_fichas('*','-');


        cant+=14;

    }
    tablero.decidir_el_ganador();


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
