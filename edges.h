#ifndef EDGES_H
#define EDGES_H

typedef struct s_edge {
  int weight ;
  int v1 ;
  int v2 ;
} edge ;

inline int leq(edge e1, edge e2) ;

typedef struct s_edge_set {
  int size ;
  edge* array ;
} edge_set ;

#endif // EDGES_H
