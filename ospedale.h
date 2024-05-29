#ifndef OSPEDALE_H
#define OSPEDALE_H

#include <iostream>
#include <fstream>

#include "grafo.h"

using namespace std;

graph fetchOspedale(char* file);
void stampa(graph g);
void infettati(graph g, int nodo);
#endif
