#include <iostream>
#include <vector>
#include <string>

#include "cartas.h"
#include "pilhas.h"
#include "operacoes.h"

using namespace std;

bool vitoria(pilha a, pilha b, pilha c, pilha d)
{
    if(a.tamanho() + b.tamanho() + c.tamanho() + d.tamanho() == 52)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    // iniciando o jogo:
    pilha baralho;
    baralho.inicializaBaralho();
	baralho.embaralha();
    pilha A, B, C, D, E, F, G, H;
    distribui(baralho, A, B, C, D, E, F, G, H);

    pilha FC1, FC2, FC3, FC4;
    pilha B1, B2, B3, B4;
    // jogo iniciado

    while(vitoria(B1, B2, B3, B4) == false)
    {
        cout << "faca uma jogada" << endl;
    }
        cout << "gg";

    return 0;
}