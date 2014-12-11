#include <stdlib.h>
#include "edges.h"

bool edge_weight_leq(edge e1, edge e2) {
  return (e1.weight <= e2.weight) ;
}

bool edge_eq(edge e1, edge e2) {
  bool same_order = (e1.v1 == e2.v1) && (e1.v2 == e2.v2) ;
  bool rev_order = (e1.v2 == e2.v1) && (e1.v1 == e2.v2) ;
  return (same_order || rev_order) ;
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
    return TOO_MANY_EDGES ;
  } else if (edge_set_is_in(set, e)) {
    return TWICE_EDGE ;
  } else {
    set.array[set.used_size] = e ;
    set.used_size += 1 ;
    return OK ;
  }
}

bool edge_set_is_in(edge_set set, edge e) {
  for(int i = 0 ; i < set.used_size ; i++) {
    if (edge_eq(e, set.array[i])) {
      return TRUE ;
    }
  }
  return FALSE ;
}
