#include <iostream>
#include "grafo.h"
#include "ospedale.h"

using namespace std;

int main() {
  char * filename = "ospedale.txt";
  graph ospedale = fetchOspedale(filename);
  
  stampa(ospedale);
  int inputInfettati;
  cout << endl << "Inserisci il nodo di partenza da cui vedere gli infetti: ";
  cin >> inputInfettati;
  infettati(ospedale, inputInfettati);
  return 0;
}
