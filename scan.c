#include "scan.h"

edge_set scan_file(FILE* f) {
  // TODO : gestion des erreurs de scanf et add_edge
  // TODO : check pas deux fois la meme arete
  //        ex 1 2 puis 2 1
  int n = 0 ;
  int m = 0 ;
  fscanf(f, "%d%d", &n, &m) ;
  edge_set s = edge_set_create(m) ;
  for (int i = 0 ; i < m ; i++) {
    edge e ;
    fscanf(f, "%d%d%d", &e.v1, &e.v2, &e.weight) ;
    add_edge(s, e) ;
  }
  return s ;
}
