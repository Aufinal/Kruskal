#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "unionfind.h"
#include "quicksort.h"
#include "edges.h"
#include "scan.h"
#include "mst.h"

const double WEIGHT_MAX = 1500 ;

double rand_w() {
  double x = ((double)rand()/(double)RAND_MAX);
  return x * WEIGHT_MAX;
}

edge_set rand_edge_set(int n, int m) {
  srand(time(NULL)) ;

  if ( n < 1 ) {
    printf("Not enough vertices\n");
    exit(1);
  }
  if ( m < n - 1 ) {
    printf("Not enough edges\n");
    exit(1);
  }
  if ( m > (n * (n - 1)) / 2) {
    printf("Too many edges\n");
    exit(1);
  }

  err_code err ;

  edge_set set = edge_set_create(m);

  for (int i = 1 ; i < n ; i++) {
    edge e ;
    e.v1 = i ;
    e.v2 = rand() % i ;
    e.weight = rand_w() ;
    add_edge(set, e) ;
  }

  for (int i = *(set.used_size); i < m ; i++) {
    edge e ;
    e.v1 = rand() % n ;
    e.v2 = rand() % n ;
    e.weight = rand_w() ;
    err = add_edge(set, e) ;
    if (err != OK) {
      i-- ;
    }
  }

  return set ;
}



int main() {

  clock_t time1 ;
  clock_t time2 ;

  for (int n = 700 ; n < 1200 ; n += 200) {
    for (int m = n ; m  < (n * (n - 1)) / 2 ; m += n * n / 6 ) {
      edge_set s = rand_edge_set(n, m) ;
      time1 = clock() ;
      edge_set mst = mst_calc(s, n) ;
      time2 = clock() ;
      float time = (time2 - time1) / CLOCKS_PER_SEC ;
      //free_edge_set(s) ;
      //free_edge_set(mst) ;
      free(s.array) ;
      free(s.used_size) ;
      free(mst.array) ;
      free(mst.used_size) ;
      printf("%d %d : %f\n", n, m, time) ;
    }
  }

  return 0 ;
}
