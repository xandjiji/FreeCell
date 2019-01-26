#ifndef CARTAS_H
#define CARTAS_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class carta
{
public:
    int numero; // A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K
    int naipe; // ouros, espadas, copas, paus
    string cor; // "vermelho" ou "preto"

    carta(int a, int b, string c) // construtor
    {
        numero = a;
        naipe = b;
        cor = c;
    }

};

#endif