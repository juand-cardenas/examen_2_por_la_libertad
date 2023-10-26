using namespace std;
#include <iostream>
#ifndef OTHELLO_H
#define OTHELLO_H
#include "othello.h"


class othello
{
private:
    char** tablero;
    int tamaño_tablero;

public:

    othello(int tamaño);
    void imprimir_tablero();
};

#endif // OTHELLO_H
