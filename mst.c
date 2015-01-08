#include "mst.h"

edge_set mst_calc(edge_set s, int n) {

  uf u = uf_create(n) ;

  int* t_edges = calloc(s.max_size, sizeof(int)) ;
  for (int i=0  ; i < s.max_size ; i++) {
    t_edges[i] = i ;
  }

  bool f(int a, int b) {
    return (s.array[a].weight <= s.array[b].weight) ;
  }

  quicksort(f, t_edges, 0, s.max_size) ;

  edge_set mst = edge_set_create(n-1) ;
  edge curr_edge ;

  for (int i=0 ; i < s.max_size ; i++) {
    curr_edge = s.array[t_edges[i]] ;
    if (uf_find(u, curr_edge.v1) != uf_find(u, curr_edge.v2)) {
      ftest_error(add_edge(mst, curr_edge)) ;
      uf_union(u, curr_edge.v1, curr_edge.v2) ;
    }
  }

  free(t_edges) ;
  uf_free(u) ;

  return mst ;
}
