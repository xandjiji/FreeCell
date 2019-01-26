#ifndef PILHAS_H
#define PILHAS_H

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
#include <cstdlib>

#include "cartas.h"

using namespace std;

class pilha
{
    public:
        vector <carta> vetor;

        int tamanho()
        { // retorna o numero de elementos na pilha
            return vetor.size();
        }

        bool vazia()
        { // verifica se a pilha esta vazia (true/false)
                if (tamanho() == 0)
                    return true;
                else
                    return false;
        }

        int topo()
        { // retorna o indice da carta que esta no topo do vetor
            if (vazia() == true)
            {
                return 0;
            }
                return tamanho()-1;
        }

        void imprime()
        { // imprime o numero e o naipe de todas as cartas da pilha
            int i;
            for(i =0; i < tamanho(); i++)
            {
                cout << vetor[i].numero << " " <<vetor[i].naipe << endl;
            }
        }

        void inicializaBaralho()
        { // preenche a pilha com cartas de A-K, todos os naipes e com as respectivas cores
            int i,j;
            string cor;

            for(i = 1; i <= 13; i++)
            {
                for(j = 1; j <= 4; j++)
                {
                    if(j == 1 || j == 3) //verifica se o naipe e ouros ou copas
                    {
                        cor = "vermelho";
                    }
                    if(j == 2 || j == 4) // verifica se o naipe e espadas ou paus
                    {
                        cor = "preto";
                    }
                vetor.push_back(carta(i,j,cor));
                }
            }
        }

        void embaralha()
        { // embaralha a pilha
            int i;
            srand(time(NULL));
            for(i = 0; i < rand()%100; i++)
            {
                random_shuffle(vetor.begin(), vetor.end());
            }
        }
};
#endif