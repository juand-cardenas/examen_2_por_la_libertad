#include <iostream>
#include <ctime>
#include <sstream>
#include "othello.h"

using namespace std;

int main()
{   //int pos_x,pos_y;
    othello hola(8);

    /*for(int i=0;i<64;i++){
        if(i%2==0){
            cout<<endl<<"turno *"<<endl;
            hola.imprimir_tablero();
            hola.recibe_ficha_x();
            hola.recibe_ficha_y();
            hola.actualizar_tablero('*');
            hola.voltear_fichas('*','-');
        }
        else{
            cout<<endl<<"turno -"<<endl;
            hola.imprimir_tablero();
            hola.recibe_ficha_x();
            hola.recibe_ficha_y();
            hola.actualizar_tablero('-');
            hola.voltear_fichas('-','*');}
    }*/
    hola.tiempo();

    return 0;
}
