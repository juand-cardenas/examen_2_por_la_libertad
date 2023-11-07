using namespace std;
#include <iostream>
#include "othello.h"
#include <ctime>
#include <sstream>
#include <iomanip>

#include<string.h>
#include <bitset>
#include <fstream>
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
        imprimir_fut_pos_x();
        cin>> posicion;
        verificar(posicion);

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

    imprimir_fut_pos_y();
    cin>> posicion;
    verificar_2(posicion);

}

void othello::imprimir_error_en_posicion(){
    //imprime un dialogo
    cout<<"la posicion ingresada no es valida. "<<endl;
}

void othello:: actualizar_tablero(char ficha){
    //cout<<"entro a actualizar tablero"<<endl;
    //esto pone la "ficha" en el tabalero, mientrans que la verificacion de la posicion sea verdaderoS
    if(verificacion==true){
        *(*(tablero+pos_x)+pos_y)=ficha;}
}

bool othello :: voltear_fichas(char ficha_alidad, char ficha_enemiga){
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
            if(cont>=1){
                 cont+=1;}
            j=0;
            }
            else{cont=0; j=0;}
        }
    }
    if(cont>0){
        for(int j=(copy_y-cont);j<copy_y;j++){
            *(*(tablero+copy_x)+j)=ficha_alidad;
        }
        verificacion=true;

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
                if(cont>=1){
                     cont+=1;}
                j=tamaño_tablero;
            }
            else{cont=0; j=tamaño_tablero;}
        }
    }
    if(cont>0){
        cout<<endl<<cont<<endl;
        for(int j=(copy_y+cont);j>copy_y;j--){
            *(*(tablero+copy_x)+j)=ficha_alidad;
        }
        verificacion=true;

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
                if(cont>=1){
                     cont+=1;}
                j=0;
            }
            else{cont=0; j=0;}
        }

    }
    if(cont>0){
        for(int j=(copy_x-cont);j<copy_x;j++){
            *(*(tablero+j)+copy_y)=ficha_alidad;
        }
        verificacion=true;

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
                if(cont>=1){
                     cont+=1;}
                j=tamaño_tablero;
        }
        else{cont=0; j=tamaño_tablero;}
        }
    }
    if(cont>0){
        for(int j=(copy_x+cont);j>copy_x;j--){
            *(*(tablero+j)+copy_y)=ficha_alidad;
        }
        verificacion=true;

    }

     //el anterior voltea de forma horizontal hacia abajo
    cont=0;
    diagonal=pos_y-1;
    for(int i=(copy_x-1);i>=0;i--){
        auxiliar=*(*(tablero+i)+diagonal);
        if(auxiliar==ficha_enemiga){
            cont+=1; diagonal-=1;
        }
        else{
            if(auxiliar==ficha_alidad){
                if(cont>=1){
                  cont+=1;}
                i=0;
            }
            else{cont=0; i=0;}
            }
    }
    if(cont>0){
            cout<<endl<<"erroe"<<endl;
        for(int i=(copy_x-cont);i<copy_x;i++){
            *(*(tablero+i)+diagonal)=ficha_alidad;
            diagonal+=1;
            }
        verificacion=true;

    }
    //cambia la diagonal superior izquierda, el condigo anterior

    cont=0;
    diagonal=pos_y-1;
    for(int i=(copy_x+1);i>=0;i++){
        auxiliar=*(*(tablero+i)+diagonal);
        if(auxiliar==ficha_enemiga){
            cont+=1; diagonal-=1;
        }
        else{
            if(auxiliar==ficha_alidad){
            if(cont>=1){
                 cont+=1;}
            i=-2;
            }
            else{cont=0; i=-2;}
            }
    }
    if(cont>0){
            for(int i=(copy_x+cont);i>copy_x;i--){
                *(*(tablero+i)+diagonal)=ficha_alidad;
                diagonal+=1;
            }
            verificacion=true;

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
                 if(cont>=1){
                      cont+=1;}
                 i=-2;
            }
            else{cont=0; i=-2;}
        }
    }
    if(cont>0){
        for(int i=(copy_x-cont);i<copy_x;i++){
            *(*(tablero+i)+diagonal)=ficha_alidad;
            diagonal-=1;
        }
        verificacion=true;

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
                if(cont>=1){
                     cont+=1;}
                i=-2;
            }
            else{cont=0; i=-2;}
        }
    }
    if(cont>0){
        for(int i=(copy_x+cont);i>copy_x;i--){
            *(*(tablero+i)+diagonal)=ficha_alidad;
            diagonal-=1;
        }
        verificacion=true;

    }
    //cambia los simbolos de la diagonal inferior derecha el anterior codigo


}

void othello :: tiempo()
{
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%h-%Y-%H-%M#");
    auto str = oss.str();
    tiemp_o=str;
    //cout<<tiemp_o;
}

void othello::abrir_txt(){
    //obtnego el contenido del txt
    abrir.open("registro.txt",ios ::in);
    if(abrir.is_open()){
        char line;
        while (abrir.good()){
            line=abrir.get();
            if(abrir.good()){
                if(line!='\n'){
                    texto=texto+line;

                }
            }
        }
        abrir.close();
    }
    //abre el txt de donde se optiene los anteriores registros para ser actulizados o impresos
}

void othello :: monstrar_el_registro(){
    abrir_txt();
//imprime la variable texto
    int tamaño;
    string aux;
    tamaño=texto.size();
    for(int i=0;i<tamaño;i++){
        aux=texto[i];
        if(aux!="#"){
            cout<<aux;
        }
        if(aux=="#"){
            cout<<aux<<endl;
        }
    }
//muestra el registro que esta almcenado en el txt
}


void othello:: guardar_texto(string nuevo){
abrir_txt();
    fout.open("registro.txt",ios ::in);
    texto=texto+nuevo;
    int tama;
    string aux;
    tama=texto.size();
    for(int i=0;i<tama;i++){
        aux=texto[i];
        if(aux=="#"){
            fout<<aux;
            fout<<'\n';
        }
        else{
            fout<<aux;
        }
    }
//cout<<endl<<texto<<endl;
    //fuarda en el txt el nombre del ganador de la ultima partida con la fecha y hora inclida
}

bool othello :: comprobar_pisicion_ingresada(char ficha_alidad, char ficha_enemiga ){
    int copy_x,copy_y,cont=0,diagonal,aux;
    char auxiliar;
    copy_x=pos_x;
    copy_y=pos_y;
    aux=*(*(tablero+pos_x)+pos_y);
    if(aux!=ficha_alidad){
        if(aux!=ficha_enemiga){

    for(int j=(copy_y-1);0<=j;j--){
        auxiliar=*(*(tablero+pos_x)+j);
        if(auxiliar==ficha_enemiga){
            cont+=1;
        }
        else{
            if(auxiliar==ficha_alidad){
                if(cont>=1){
                     cont+=1;}
                j=0;
            }
            else{cont=0; j=0;}
        }
    }
    if(cont>0){

        validar=true;
        return true;
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
                if(cont>=1){
                     cont+=1;}
                j=tamaño_tablero;
        }
        else{cont=0; j=tamaño_tablero;}
        }
    }
    if(cont>0){

        validar=true;
        return true;

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
            if(cont>=1){
                     cont+=1;}
                j=0;
            }
            else{cont=0; j=0;}
        }

    }
    if(cont>0){

        validar=true;
        return true;
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
                if(cont>=1){
                     cont+=1;}
                j=tamaño_tablero;
        }
        else{cont=0; j=tamaño_tablero;}
        }
    }
    if(cont>0){

        validar=true;
        return true;
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
            if(cont>=1){
                     cont+=1;}
            i=0;
            }
            else{cont=0; i=0;}
        }
    }
    if(cont>0){

        validar=true;
        return true;

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
                if(cont>=1){
                     cont+=1;}
                i=-2;
            }
            else{cont=0; i=-2;}
        }
    }
    if(cont>0){

        validar=true;
        return true;
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
                if(cont>=1){
                 cont+=1;}
                i=-2;
            }
            else{cont=0; i=-2;}
        }
    }
    if(cont>0){

        validar=true;
        return true;

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
                if(cont>=1){
                 cont+=1;}
                    i=-2;

            }
            else{cont=0; i=-2;}
        }
    }
    if(cont>0){

        validar=true;
        return true;

    }
    }
        return false;
}
    //comprueba si en la posicion indicada se puede poner una fichas segun las reglas o no
}


void othello:: ingresar_nombre_B(){
    cout<<"el jugador de la ficha Blanca "<< "* "<<" ingresa su nombre: ";
    //saca el emnsaje de arriba a la pantalla
}

void othello:: ingresar_nombre_N(){
    cout<<"el jugador de la ficha Negra "<< "- "<<" ingresa su nombre: ";
    //saca el emnsaje de arriba a la pantalla
}

void othello:: recibir_nombres(){
    ingresar_nombre_B();
    cin>>nombre_blanca;
    ingresar_nombre_N();
    cin>>nombre_negra;
    //guarda os nombres ingresados en una variable
}

void othello:: contar_fichas(){

    cantidad_b=0;
    cantidad_n=0;
    char auxiliar_1;
    for(int i=1;i<=tamaño_tablero-2;i++){
        for(int j=1;j<=tamaño_tablero-2;j++){
            auxiliar_1=*(*(tablero+i)+j);
            if(auxiliar_1=='*'){
                cantidad_b+=1;
            }
            if(auxiliar_1=='-'){
                cantidad_n+=1;
            }
        }
    }
    //cout<<endl<<cantidad_b<<"  "<<cantidad_n<<endl;
    //cuenta la cantidad de fichaas que hay en el tablero
}


void othello:: decidir_el_ganador(){
    string auxi_2,auxi_3,auxi_4;
    contar_fichas();
    tiempo();
    if(cantidad_b<cantidad_n){
        auxi_3=to_string(cantidad_n);
        auxi_4=to_string(cantidad_b);
        auxi_2=nombre_negra +" gano con "+ auxi_3+ " fichas"+", "+nombre_blanca +" perdio "+"con "+auxi_4+" fichas "+ tiemp_o;
    }
    if(cantidad_b>cantidad_n){
        auxi_3=to_string(cantidad_b);
        auxi_4=to_string(cantidad_n);
        auxi_2=nombre_blanca +" gano con "+ auxi_3+" fichas"+ ", "+nombre_negra +" perdio "+"con "+auxi_4+" fichas "+ tiemp_o;
    }
    if(cantidad_b==cantidad_n){
        auxi_2="empate "+ tiemp_o;
    }
    //cout<<endl<<auxi_2<<endl;
    cout<<endl<<auxi_2<<endl;
    guardar_texto(auxi_2);
    //mediante la cantidad de ficha de cada color se deside el gandor de la partida
}


bool othello:: ver_si_hay_jugada(char ficha_alidad, char ficha_enemiga){
    char aux;
    for(int d=1;d<=tamaño_tablero-2;d++){
        for(int z=1;z<=tamaño_tablero-2;z++){
            aux=*(*(tablero+d)+z);
            //cout<<endl<<d<<"  "<<z<<endl;
            if(aux!='*'){
                if(aux!='-'){
                    int copy_x,copy_y,cont=0,diagonal;
                    char auxiliar;
                    copy_x=d;
                    copy_y=z;
                    for(int j=(copy_y-1);0<=j;j--){
                        auxiliar=*(*(tablero+d)+j);
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
                        return true;
                    }
                    //lo anterior, comprueba el lado izquierdo de la ficha, de tal forma, si se puede voltear fichas para
                    //ese lado se hara, de lo contrario no se volteara las fichas
                    cont=0;
                    for(int j=(copy_y+1);j<=tamaño_tablero-1;j++){
                        auxiliar=*(*(tablero+d)+j);
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
                        return true;
                    }
                    //lo anterior, comprueba el lado derecho de la ficha, de tal forma, si se puede voltear fichas para
                    //ese lado se hara, de lo contrario no se volteara las fichas
                    cont=0;
                    for(int j=(copy_x-1);0<=j;j--){
                        auxiliar=*(*(tablero+j)+z);
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
                        return true;
                    }
                    //el anterior voltea de forma horizontal hacia arriba
                    cont=0;
                    for(int j=(copy_x+1);j<=tamaño_tablero-1;j++){
                        auxiliar=*(*(tablero+j)+z);
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
                        return true;
                    }

                    //el anterior voltea de forma horizontal hacia abajo
                    cont=0;
                    diagonal=z-1;
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
                        return true;
                    }
                    //cambia la diagonal superior izquierda, el condigo anterior

                    cont=0;
                    diagonal=z-1;
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
                        return true;
                    }
                    //cambia los simbolos de la diagonal inferior izquierda-- el anterior codigo
                    cont=0;
                    diagonal=z+1;
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
                        return true;
                    }
                    //cambia los simbolos de la diagonal superiror derecha el anterior codigo
                    cont=0;
                    diagonal=z+1;
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
                        return true;
                    }
                    //cambia los simbolos de la diagonal inferior derecha el anterior codigo

                }
            }
        }
    }
    return false;
}
