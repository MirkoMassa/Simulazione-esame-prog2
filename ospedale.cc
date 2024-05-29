#include <iostream>
#include <fstream>

#include "grafo.h"
#include "ospedale.h"

using namespace std;

graph fetchOspedale(char* file) {
  fstream f(file);
  int n; // numero nodi
  int m; // numero archi
  
  if (f.is_open()) {
    f >> n >> m;
    graph g = new_graph(n);

    // Fetch nodi
    for (int i = 0; i < n; i++) {
      int nodeID;
      char MedOrCit, PosOrNeg;
      f >> nodeID >> MedOrCit >> PosOrNeg;
      g.nodes_info[nodeID - 1].MedOrCit = MedOrCit;
      g.nodes_info[nodeID - 1].PosOrNeg = PosOrNeg;
    }

    // Fetch archi
    for (int i = 0; i < m; i++) {
      int nodeu, nodev;
      f >> nodeu >> nodev;
      add_edge(g, nodeu, nodev);
    }
    f.close();
    return g;
  }
}

void stampa(graph g) {
  for (int i = 0; i < get_dim(g); i++) {
    if (g.nodes_info[i].MedOrCit == 'M') { // Se Medico
      adj_list adj = get_adjlist(g, i + 1);
      while (adj != NULL) {
        int idx = get_adjnode(adj) - 1;
        if (g.nodes_info[idx].MedOrCit == 'C' && g.nodes_info[idx].PosOrNeg == 'P') {
          cout << "Il medico " << (i + 1) << " cura il paziente " << (idx + 1) << endl;
        }
        adj = get_nextadj(adj);
      }
    }
  }
}

void infettati(graph g, int nodo) {
  adj_list adj = get_adjlist(g, nodo);
  while (adj != NULL) {
    int idx = get_adjnode(adj) - 1;
    if (g.nodes_info[idx].PosOrNeg == 'P') {
      cout << "Paziente positivo: "<< idx+1 << endl;
    }
    adj = get_nextadj(adj);
  }
  
}