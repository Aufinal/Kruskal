#include "mst.h"

int main()
{
  char name[256] ;
  printf("File to scan : ") ;
  char * p_name = name ;
  scanf("%s", p_name) ;

  edge_set s ;
  int n, i=0 ;
  ftest_error(scan_file(p_name, &s, &n)) ;
 
  edge_set mst = mst_calc(s, n) ;

  printf("Minimal spanning tree :\n") ;
  double total_weight ;

  for (i=0 ; i<n-1 ; i++) {
    printf("%d %d %lf\n", mst.array[i].v1, mst.array[i].v2, mst.array[i].weight) ;
    total_weight += mst.array[i].weight ;
  }

  printf("Total weight : %lf\n", total_weight) ;

  return 0 ;
}
