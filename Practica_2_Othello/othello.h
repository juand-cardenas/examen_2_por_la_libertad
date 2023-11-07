using namespace std;
#include <iostream>
#include <iomanip>
#ifndef OTHELLO_H
#define OTHELLO_H
#include "othello.h"
#include <ctime>

#include<string.h>
#include <sstream>
#include <bitset>
#include <fstream>

class othello
{
private:


    char** tablero;
    int tamaño_tablero;
        int posicion;
    int pos_x,pos_y;
    string tiemp_o;
    string texto;
    ifstream abrir;
    ofstream fout;
    int cantidad_b;
    int cantidad_n;



    void imprimir_error_en_posicion();
    void imprimir_fut_pos_x();
    void verificar_2(int y);
    void verificar(int x);
    void imprimir_fut_pos_y();
    void abrir_txt();
    void guardar_texto(string nuevo);
    void ingresar_nombre_N();
    void ingresar_nombre_B();
    void contar_fichas();


public:

    bool validar;
    bool verificacion;
    string nombre_negra;
    string nombre_blanca;
    othello(int tamaño);
        bool comprobar_pisicion_ingresada(char ficha_alidad, char ficha_enemiga );
    void recibir_nombres();
    void monstrar_el_registro();
    void tiempo();
    void decidir_el_ganador();
    bool posicion_valida;
    bool ver_si_hay_jugada(char ficha_alidad, char ficha_enemiga);
    void imprimir_tablero();
    void recibe_ficha_x();
    void recibe_ficha_y();
    void actualizar_tablero(char ficha);
    bool voltear_fichas(char ficha_alidad, char ficha_enemiga);


    //bool P_Validar_pos(int pos_x,int pos_y);


    //bool terminarjuego(bool Val_pos,int &Cant_fB,int &Cant_fN,int tamaño);

};

#endif // OTHELLO_H
