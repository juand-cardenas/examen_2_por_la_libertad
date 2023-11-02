using namespace std;
#include <iostream>
#include <iomanip>
#ifndef OTHELLO_H
#define OTHELLO_H
#include "othello.h"
#include <ctime>
#include <sstream>

class othello
{
private:

    char** tablero;
    int tamaño_tablero;
    int posicion;
    int pos_x,pos_y;
    bool verificacion=true;
    void imprimir_error_en_posicion();
    void imprimir_fut_pos_x();
    void verificar_2(int y);
    void verificar(int x);
    void imprimir_fut_pos_y();
    bool Validar_pos(int pos_x,int pos_y);
    bool Posibilidad_jugada();


public:

    void tiempo();
    bool posicion_valida;
    othello(int tamaño);
    void imprimir_tablero();
    void recibe_ficha_x();
    void recibe_ficha_y();
    void actualizar_tablero(char ficha);
    void voltear_fichas(char ficha_alidad, char ficha_enemiga);
    bool P_Posibilidad_jugada();
    bool P_Validar_pos(int pos_x,int pos_y);


    //bool terminarjuego(bool Val_pos,int &Cant_fB,int &Cant_fN,int tamaño);

};

#endif // OTHELLO_H
