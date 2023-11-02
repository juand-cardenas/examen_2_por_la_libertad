using namespace std;
#include <iostream>
#include "othello.h"
#include <ctime>
#include <sstream>
#include <iomanip>
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
    //imprime el tablero
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
    //imprime un dialogo
    cout<<"escriba la poscion en x donde quiere que quede su ficha: ";
}


void othello::verificar(int x)
{
    //comprueba que sea valida la posicion
    //posicion_valida=false;
    int tama_tab;
    tama_tab=tamaño_tablero-2;
    if(0<x and x<=tama_tab){pos_x=x; posicion_valida=true;}
    else {imprimir_error_en_posicion();
        posicion_valida=false;}
}


void othello ::recibe_ficha_x(){
    //esto recibe la posicion del tablero
    bool v = true;
    while(v)
    {
        imprimir_fut_pos_x();
        cin>> posicion;
        verificar(posicion);
        if (posicion_valida)
        {
            v = false;
        }
    }
}

void othello::verificar_2(int y){
    int tama_tab;
    tama_tab=tamaño_tablero-2;
    if(0<y and y<=tama_tab){pos_y=y; posicion_valida=true;}
    else {imprimir_error_en_posicion();
        posicion_valida=false;}

}


void othello::imprimir_fut_pos_y(){
    //imprime un dialogo
    cout<<endl<<"escriba la poscion en y donde quiere que quede su ficha: ";
}

void othello ::recibe_ficha_y()
{
    bool v = true;
    while(v)
    {
        imprimir_fut_pos_y();
        cin>> posicion;
        verificar_2(posicion);
        if (posicion_valida)
        {
            v = false;
        }
    }
}

void othello::imprimir_error_en_posicion(){
    //imprime un dialogo
    cout<<"la posicion ingresada no es valida. "<<endl;
}

void othello:: actualizar_tablero(char ficha){
    cout<<"entro a actualizar tablero"<<endl;
    //esto pone la "ficha" en el tabalero, mientrans que la verificacion de la posicion sea verdaderoS
    if(verificacion==true){
        *(*(tablero+pos_x)+pos_y)=ficha;}
}

void othello :: voltear_fichas(char ficha_alidad, char ficha_enemiga){
    int copy_x,copy_y,cont=0,diagonal;
    char auxiliar;
    copy_x=pos_x;
    copy_y=pos_y;
    for(int j=(copy_y-1);0<=j;j--){
        auxiliar=*(*(tablero+pos_x)+j);
        if(auxiliar==ficha_enemiga){
            cont+=1;
        }
        else{
            if(auxiliar==ficha_alidad){
                j=0; cont+=1;
            }
            else{cont=0; j=0;}
        }
    }
    if(cont>0){
        for(int j=(copy_y-cont);j<copy_y;j++){
            *(*(tablero+copy_x)+j)=ficha_alidad;
        }
    }
    //lo anterior, comprueba el lado izquierdo de la ficha, de tal forma, si se puede voltear fichas para
    //ese lado se hara, de lo contrario no se volteara las fichas
    cont=0;
    for(int j=(copy_y+1);j<=tamaño_tablero-1;j++){
        auxiliar=*(*(tablero+pos_x)+j);
        if(auxiliar==ficha_enemiga){
            cont+=1;
        }
        else{
            if(auxiliar==ficha_alidad){
                j=tamaño_tablero; cont+=1;
            }
            else{cont=0; j=tamaño_tablero;}
        }
    }
    if(cont>0){
        for(int j=(copy_y+cont);j>copy_y;j--){
            *(*(tablero+copy_x)+j)=ficha_alidad;
        }
    }
    //lo anterior, comprueba el lado derecho de la ficha, de tal forma, si se puede voltear fichas para
    //ese lado se hara, de lo contrario no se volteara las fichas
    cont=0;
    for(int j=(copy_x-1);0<=j;j--){
        auxiliar=*(*(tablero+j)+pos_y);
        if(auxiliar==ficha_enemiga){
            cont+=1;
        }
        else{
            if(auxiliar==ficha_alidad){
                j=0; cont+=1;
            }
            else{cont=0; j=0;}
        }
    }
    if(cont>0){
        for(int j=(copy_x-cont);j<copy_x;j++){
            *(*(tablero+j)+copy_y)=ficha_alidad;
        }
    }
    //el anterior voltea de forma horizontal hacia arriba
    cont=0;
    for(int j=(copy_x+1);j<=tamaño_tablero-1;j++){
        auxiliar=*(*(tablero+j)+pos_y);
    if(auxiliar==ficha_enemiga){
        cont+=1;
    }
    else{
        if(auxiliar==ficha_alidad){
            j=tamaño_tablero; cont+=1;
        }
        else{cont=0; j=tamaño_tablero;}
        }
    }
    if(cont>0){
        for(int j=(copy_x+cont);j>copy_x;j--){
            *(*(tablero+j)+copy_y)=ficha_alidad;
        }
    }

     //el anterior voltea de forma horizontal hacia abajo
    cont=0;
    diagonal=pos_y-1;
    for(int i=(copy_x-1);i>0;i--){
        auxiliar=*(*(tablero+i)+diagonal);
        if(auxiliar==ficha_enemiga){
            cont+=1; diagonal-=1;
        }
        else{
            if(auxiliar==ficha_alidad){
            i=0; cont+=1;
            }
            else{cont=0; i=0;}
            }
    }
    if(cont>0){
        for(int i=(copy_x-cont);i<copy_x;i++){
            *(*(tablero+i)+diagonal)=ficha_alidad;
            diagonal+=1;
            }
    }
    //cambia la diagonal superior izquierda, el condigo anterior

    cont=0;
    diagonal=pos_y-1;
    for(int i=(copy_x+1);i>0;i++){
        auxiliar=*(*(tablero+i)+diagonal);
        if(auxiliar==ficha_enemiga){
            cont+=1; diagonal-=1;
        }
        else{
            if(auxiliar==ficha_alidad){
                 i=-2; cont+=1;
            }
            else{cont=0; i=-2;}
            }
    }
    if(cont>0){
            for(int i=(copy_x+cont);i>copy_x;i--){
                *(*(tablero+i)+diagonal)=ficha_alidad;
                diagonal+=1;
            }
    }
    //cambia los simbolos de la diagonal inferior izquierda-- el anterior codigo
    cont=0;
    diagonal=pos_y+1;
    for(int i=(copy_x-1);0<=i;i--){
        auxiliar=*(*(tablero+i)+diagonal);
        if(auxiliar==ficha_enemiga){
            cont+=1; diagonal+=1;
        }
        else{
            if(auxiliar==ficha_alidad){
                i=-2; cont+=1;
            }
            else{cont=0; i=-2;}
        }
    }
    if(cont>0){
        for(int i=(copy_x-cont);i<copy_x;i++){
            *(*(tablero+i)+diagonal)=ficha_alidad;
            diagonal-=1;
        }
    }
    //cambia los simbolos de la diagonal superiror derecha el anterior codigo
    cont=0;
    diagonal=pos_y+1;
    for(int i=(copy_x+1);0<i;i++){
        auxiliar=*(*(tablero+i)+diagonal);
        if(auxiliar==ficha_enemiga){
            cont+=1; diagonal+=1;
        }
        else{
            if(auxiliar==ficha_alidad){
                i=-2; cont+=1;
            }
            else{cont=0; i=-2;}
        }
    }
    if(cont>0){
        for(int i=(copy_x+cont);i>copy_x;i--){
            *(*(tablero+i)+diagonal)=ficha_alidad;
            diagonal-=1;
        }
    }
    //cambia los simbolos de la diagonal inferior derecha el anterior codigo
}

void othello :: tiempo()
{
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%h-%Y-%H-%M-");
    auto str = oss.str();
    string df=str;
}
bool othello::Validar_pos(int pos_x,int pos_y)
{
    if((*(*(tablero+pos_x)+pos_y) = '*')||(*(*(tablero+pos_x)+pos_y) = '-'))
    {
        cout << "La posicion ingresada ya esta ocupada" << endl;
        return false;
    }
    else {return true;}
}

bool othello::Posibilidad_jugada()
{
    return true;//crear funcion
}

bool othello::P_Posibilidad_jugada()
{
    return Posibilidad_jugada();
}

bool othello::P_Validar_pos(int x,int y)
{
    return Validar_pos(x,y);
}


