#ifndef GRAFO_H
#define GRAFO_H

#include "tipo.h";

typedef struct adj_node {
  int node;
  struct adj_node* next;
} adj_node;

typedef adj_node* adj_list;

typedef struct {
  int dim;
  adj_list* nodes;
  tipo_inf* nodes_info;
} graph;

graph new_graph(int n);
void add_arc(graph& G, int u, int v);
void add_edge(graph& g, int u, int v);
int get_dim(graph g);
adj_list get_adjlist(graph g, int u);
int get_adjnode(adj_node* l);
adj_list get_nextadj(adj_list l);

#endif
