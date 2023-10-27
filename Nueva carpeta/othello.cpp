using namespace std;
#include <iostream>
#include "othello.h"

othello::othello(int tamaño)
{   int mitad,mitad_h,tamaño_1;
        tamaño_tablero=tamaño+2;
        tamaño_1=tamaño+2;
        if(tamaño%2==0){
            tablero= new char*[tamaño_1];
            for(int i=0;i<tamaño_1;i++){
                tablero[i]= new char [tamaño_1];
        }
        for(int i=1;i<tamaño_1;i++){
            for(int j=1;j<tamaño_1;j++){
                *(*(tablero +i)+j)=' ';
            }
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

                *(*(tablero +i)+j)=j + 0x30;
                *(*(tablero +j)+i)=j + 0x30;
            }
        }
        //pongo los numeros en los marcos para que el jugador coloque la coordenada donde quiere que este su ficha
        for(int i=tamaño_1-1;i<tamaño_1;i++){
            for(int j=0;j<tamaño_1;j++){
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
        cout<< "| "<<endl;
        for(int i=0;i<tamaño_tablero;i++){
            cout<<"----";
        }
        cout<<endl;
    }

}



void othello::imprimir_fut_pos_x(){
    cout<<"escriba la poscion en x donde quiere que quede su ficha: ";
}

void othello ::recibe_ficha_x(){
    int x,tama_tab;
    cin>>x;
    tama_tab=tamaño_tablero-2;
    if(0<x<=tama_tab){pos_x=x; }
    else {imprimir_error_en_posicion();}
}

void othello::imprimir_fut_pos_y(){
    cout<<"escriba la poscion en y donde quiere que quede su ficha: ";
}

void othello ::recibe_ficha_y(){
    int y,tama_tab;
    cin>>y;
    tama_tab=tamaño_tablero-2;
    if(0<y<=tama_tab){pos_y=y; }
    else {imprimir_error_en_posicion();}
    *(*(tablero+pos_x)+pos_y);
}

void othello::imprimir_error_en_posicion(){
    cout<<"la posicion ingresada no es valida.";
}
