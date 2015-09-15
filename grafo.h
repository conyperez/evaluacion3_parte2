#ifndef STDIO_H
#include <stdio.h>
#define STDIO_H
#endif

#ifndef STDLIB_H
#include <stdlib.h>
#define STDLIB_H
#endif

#ifndef LISTA_H
#include "lista.h"
#define LISTA_H
#endif

#ifndef COLA_H
#include "cola.h"
#define COLA_H
#endif

#define tam 9

typedef NodoLista VECINO;

typedef struct _nodo{
	int padre;
	int distancia;
	VECINO *vecino;
}Nodo;

int inicializaVectores(Nodo grafo[tam]){
    int i;
	for(i=0; i<tam; i++){
		grafo[i].vecino = NULL;
	}
	return 1;
}

int agregaArista(Nodo grafo[tam], int i, int j, int w){    // Agrega arista dirigida
    grafo[i].vecino = insertaNodo(grafo[i].vecino, j, w);
    return 1;
}

void Relax(Nodo grafo[tam], int u, int v, int w){
    if(grafo[v].distancia > grafo[u].distancia + w){
        grafo[v].distancia = grafo[u].distancia + w;
        grafo[v].padre = u;
    }
}

int dijkstra(Nodo grafo[tam], int w, int s){
    int i;
    for(i=0; i<tam; i++){
        grafo[i].distancia = -1;
        grafo[i].padre = -1;
        grafo[i].visto = 0;
    }
    grafo[s].distancia = 0;
    // Inicializar S
    Cola *Q = creaCola(tam);
    // Pasar vector a la cola
    while(!esVaciaCola(Q)){
        int u = extraerMinimo(Q);
        // Pasar u a S
        VECINO *aux = grafo[u].vecino;
        while(aux != NULL){
            Relax(grafo, u, aux->idNodo, w);
            aux = aux->sgte;
        }
    }
    return 1;
}
