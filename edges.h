#ifndef EDGES_H
#define EDGES_H

#include "errors.h"
#include "bool.h"

typedef struct s_edge {
  int weight ;
  int v1 ;
  int v2 ;
} edge ;

bool edge_weight_leq(edge e1, edge e2) ;
bool edge_eq(edge e1, edge e2) ;

typedef struct s_edge_set {
  int max_size ;
  int* used_size ;
  edge* array ;
} edge_set ;

edge_set edge_set_create(int max_size) ;
err_code add_edge(edge_set set, edge e) ;
bool edge_set_is_in(edge_set set, edge e) ;

#endif // EDGES_H
