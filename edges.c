#include <stdlib.h>
#include "edges.h"

int leq(edge e1, edge e2) {
  return (e1.weight <= e2.weight) ;
}

edge_set edge_set_create(int max_size) {
  edge_set s ;
  s.max_size = max_size ;
  s.used_size = 0 ;
  s.array = calloc(max_size, sizeof(edge)) ;
  return s ;
}

err_code add_edge(edge_set set, edge e) {
  if (set.max_size == set.used_size) {
    return EXCEED_CAP ;
  } else {
    set.array[set.used_size] = e ;
    set.used_size += 1 ;
    return OK ;
  }
}
