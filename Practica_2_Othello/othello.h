#include <iostream>
#ifndef OTHELLO_H
#define OTHELLO_H

using namespace std;

class othello
{
public:

othello(short int tamaño);
void imprimir_tablero();


private:

char** tablero;
int tamaño_tablero;



};

#endif // OTHELLO_H
