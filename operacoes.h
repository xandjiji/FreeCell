#ifndef OPERACOES_H
#define OPERACOES_H

#include <iostream>
#include <vector>
#include <string>

#include "cartas.h"
#include "pilhas.h"

using namespace std;

bool empilha(pilha &origem, pilha &destino)
{ // tira carta da pilha X e coloca na pilha Y (retorna true/false)
    bool DeuCerto;

    if(origem.vazia() == false)
    {
        destino.vetor.push_back(origem.vetor[origem.topo()]); //pilha destino recebe carta do topo da pilha origem
        origem.vetor.pop_back(); //pilha origem perde sua carta topo;

        DeuCerto = true;
        return DeuCerto;
    }
    else
    {
        DeuCerto = false;
        return DeuCerto;
    }
}

void distribui(pilha &baralho, pilha &a, pilha &b, pilha &c, pilha &d, pilha &e, pilha &f, pilha &g, pilha &h)
{ // distribui todas as cartas de uma pilha para as 8 pilhas iniciais
    while(baralho.vazia() != true)
    {
        empilha(baralho, a);
        empilha(baralho, b);
        empilha(baralho, c);
        empilha(baralho, d);
        empilha(baralho, e);
        empilha(baralho, f);
        empilha(baralho, g);
        empilha(baralho, h);
    }
}

bool empilhaFreeCell(pilha &origem, pilha &destino)
{ // empilha numa "FreeCell" apenas se ela estiver vazia
    bool DeuCerto;
    if(destino.tamanho() == 0)
    {
        empilha(origem, destino);
        DeuCerto = true;
        return DeuCerto;
    }
    else
    {
        DeuCerto = false;
        return DeuCerto;
    }
}

bool empilhaDireito(pilha &origem, pilha &destino)
{ // empilha se forem cartas em sequencia decrescente e de cores diferentes
    bool DeuCerto;
    if(destino.tamanho() == 0)
    {
        empilha(origem, destino);
        DeuCerto = true;
        return DeuCerto;
    }
    if(origem.vetor[origem.topo()].cor != destino.vetor[destino.topo()].cor)
    {
        if(origem.vetor[origem.topo()].numero+1 == destino.vetor[destino.topo()].numero)
        {
            empilha(origem, destino);
            DeuCerto = true;
            return DeuCerto;
        }
    }
    else
    {
        DeuCerto = false;
        return DeuCerto;
    }
}

bool empilhaBase(pilha &origem, pilha &destino)
{ // empilha apenas cartas de mesmo naipe em sequencia crescente
    bool DeuCerto;
    if(destino.tamanho() == 0)
    {
        if(origem.vetor[origem.topo()].numero == 1)
        {
            empilha(origem, destino);
            DeuCerto = true;
            return DeuCerto;
        }
        else
        {
            DeuCerto = false;
            return DeuCerto;
        }
    }
    if(origem.vetor[origem.topo()].naipe == destino.vetor[destino.topo()].naipe)
    {
        if(origem.vetor[origem.topo()].numero == destino.vetor[destino.topo()].numero+1)
        {
            empilha(origem, destino);
            DeuCerto = true;
            return DeuCerto;
        }
        else
        {
            DeuCerto = false;
            return DeuCerto;
        }
    }
    else
    {
        DeuCerto = false;
        return DeuCerto;
    }
}
#endif