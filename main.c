#ifndef STDIO_H
#include <stdio.h>
#define STDIO_H
#endif

#ifndef STDLIB_H
#include <stdlib.h>
#define STDLIB_H
#endif

#ifndef GRAFO_H
#include "grafo.h"
#define GRAFO_H
#endif

#define tam 9

typedef Nodo Grafo;

int main(){

  Grafo grafo[tam];

  inicializaVectores(grafo);

  agregaArista(grafo, 0, 1, 7);
  agregaArista(grafo, 0, 2, 5);
  agregaArista(grafo, 1, 4, 3);
  agregaArista(grafo, 1, 5, 7);
  agregaArista(grafo, 2, 1, 3);
  agregaArista(grafo, 2, 7, 9);
  agregaArista(grafo, 3, 5, 6);
  agregaArista(grafo, 4, 3, 2);
  agregaArista(grafo, 4, 7, 3);
  agregaArista(grafo, 5, 6, 1);
  agregaArista(grafo, 5, 7, 2);
  agregaArista(grafo, 6, 7, 10);
  agregaArista(grafo, 7, 8, 6);

  dijkstra(grafo, 0, 0);

  return 0;
}
