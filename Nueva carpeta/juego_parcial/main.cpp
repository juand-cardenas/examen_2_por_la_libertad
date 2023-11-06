#include <iostream>
#include <ctime>
#include <sstream>
#include "othello.h"
#include<string.h>
#include <bitset>
#include <fstream>

using namespace std;

int main()
{
    othello tablero(8);
    int selecion,cont=0;
    cout<<"si desea jugar escriba el numero 2, si desea ver el registro ingrese el numero 1: "<<endl;
    cin>>selecion;
    if(selecion==1){
        tablero.monstrar_el_registro();
    }
    if(selecion==2){
        tablero.recibir_nombres();
        while (cont<12) {
            if(tablero.ver_si_hay_jugada('-','*')){
            tablero.verificacion=false;
            while(!tablero.verificacion){
                //cout<<endl<<"dentro del while"<<endl;
                    cout<<endl<<"el turno es de "<<tablero.nombre_negra<<endl;
                    tablero.imprimir_tablero();
                    tablero.posicion_valida=false;
                    while (!tablero.posicion_valida) {
                        tablero.recibe_ficha_x();
                    }
                    tablero.posicion_valida=false;
                    while (!tablero.posicion_valida) {
                        tablero.recibe_ficha_y();
                    }
                    if(tablero.comprobar_pisicion_ingresada('-','*')){
                        tablero.verificacion=false;
                        tablero.voltear_fichas('-','*');
                        tablero.actualizar_tablero('-');


                    }
                    else{cout<<endl<<"poisicion no valida, ingrese una nueva"<<endl;}
                }
            }

            if(tablero.ver_si_hay_jugada('*','-')){
            tablero.verificacion=false;
            while(!tablero.verificacion){
                //cout<<endl<<"dentro del while"<<endl;
                    cout<<endl<<"el turno es de "<<tablero.nombre_blanca<<endl;
                    tablero.imprimir_tablero();
                    tablero.posicion_valida=false;
                    while (!tablero.posicion_valida) {
                        tablero.recibe_ficha_x();
                    }
                    tablero.posicion_valida=false;
                    while (!tablero.posicion_valida) {
                        tablero.recibe_ficha_y();
                    }
                    if(tablero.comprobar_pisicion_ingresada('*','-')){
                        tablero.verificacion=false;
                        tablero.voltear_fichas('*','-');
                        tablero.actualizar_tablero('*');


                    }
                    else{cout<<endl<<"poisicion no valida, ingrese una nueva"<<endl;}
                }
            }

            if(!tablero.ver_si_hay_jugada('*','-') and !tablero.ver_si_hay_jugada('-','*')){
                cont=12;
                tablero.decidir_el_ganador();
            }
        }
    }



    return 0;
}

