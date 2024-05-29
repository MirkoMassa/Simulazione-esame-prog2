#include <iostream>
#include <stdlib.h>

#include "grafo.h"
#include "ospedale.h"

using namespace std;

graph new_graph(int n) {
  graph G;
  G.dim = n;
  G.nodes = new adj_list[n];
  for (int i = 0; i < n; i++) {
    G.nodes[i] = NULL;
  }
  G.nodes_info = new tipo_inf[n];
  return G;
}

void add_arc(graph& G, int u, int v) {
  adj_node* t = new adj_node;
  t->node = v - 1;
  t->next = G.nodes[u - 1];
  G.nodes[u - 1] = t;
}

void add_edge(graph& g, int u, int v) {
  add_arc(g, u, v);
  add_arc(g, v, u);
}

int get_dim(graph g) {
  return g.dim;
}

adj_list get_adjlist(graph g, int u) {
  return g.nodes[u - 1];
}

int get_adjnode(adj_node* l) {
  return (l->node + 1);
}

adj_list get_nextadj(adj_list l) {
  return l->next;
}
