using namespace std;
#include <iostream>
#include "othello.h"

othello::othello(int tamaño)
{   int mitad,mitad_h,tamaño_1;
        tamaño_tablero=tamaño+1;
        tamaño_1=tamaño+1;
        if(tamaño%2==0){
            tablero= new char*[tamaño_1];
            for(int i=0;i<tamaño_1;i++){
                tablero[i]= new char [tamaño_1];
        }
        //con lo de acontiniacion se define las fichas iniciales
        mitad=tamaño/2;
        mitad_h=mitad;
        *(*(tablero + mitad)+mitad_h)= '*';
        mitad+=1;
        *(*(tablero + mitad)+mitad_h)= '-';
        mitad_h=mitad;
        *(*(tablero + mitad)+mitad_h)= '*';
        mitad=tamaño/2;
        *(*(tablero + mitad)+mitad_h)= '-';
        // con lo que sigue se hara el marco del tablero
        for(int i=0;i<1;i++){
            for(int j=0; j<tamaño_1;j++){
                 char d=static_cast<char>(i);
                *(*(tablero +i)+j)=j + 0x30;
                *(*(tablero +j)+i)=j + 0x30;
            }
        }

    }
    else{cout<<"El tamaño no es valido"<<endl;}

}


void othello::imprimir_tablero(){
    for(int i=0;i<tamaño_tablero;i++){
        cout<<"----";
    }
    cout<<endl;
    for(int i=0; i<tamaño_tablero;i++){

        for(int j=0; j<tamaño_tablero;j++){
            cout<< " | ";
            cout<< *(*(tablero+i)+j);
        }
        cout<< " | "<<endl;
        for(int i=0;i<tamaño_tablero;i++){
            cout<<"----";
        }
        cout<<endl;
    }

}
