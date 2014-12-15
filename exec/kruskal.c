#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "unionfind.h"
#include "quicksort.h"
#include "edges.h"
#include "scan.h"

int main()
{
  char name[256] ;
  printf("File to scan : ") ;
  char * p_name = name ;
  scanf("%s", p_name) ;

  edge_set s ;
  int n, i=0 ;
  ftest_error(scan_file(p_name, &s, &n)) ;

  uf u = uf_create(n) ;

  int* t_edges = calloc(s.max_size, sizeof(int)) ;
  for ( ; i < s.max_size ; i++) {
    t_edges[i] = i ;
  }

  bool f(int a, int b) {
    return (s.array[a].weight <= s.array[b].weight) ;
  }

  quicksort(f, t_edges, 0, s.max_size) ;

  edge_set mst = edge_set_create(n-1) ;
  int total_weight = 0 ;
  edge curr_edge ;

  for (i=0 ; i < s.max_size ; i++) {
    curr_edge = s.array[t_edges[i]] ;
    if (uf_find(u, curr_edge.v1) != uf_find(u, curr_edge.v2)) {
      ftest_error(add_edge(mst, curr_edge)) ;
      total_weight += curr_edge.weight ;
      uf_union(u, curr_edge.v1, curr_edge.v2) ;
    }
  }

  printf("Minimal spanning tree :\n") ;

  for (i=0 ; i<n-1 ; i++) {
    printf("%d %d %lf\n", mst.array[i].v1, mst.array[i].v2, mst.array[i].weight) ;
  }

  printf("Total weight : %d\n", total_weight) ;

  return 0 ;
}
