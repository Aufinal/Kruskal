#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "edges.h"
#include "errors.h"

const int WEIGHT_MAX = 1500 ;

int main () {
  srand(time(NULL)) ;
  int n, m ;
  char name[256];
  printf("Number of vertices : ");
  scanf("%d", &n) ; //sommets
  printf("Number of edges : ");
  scanf("%d", &m) ; //aretes

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
    e.weight = (rand() % WEIGHT_MAX) + 1 ;
    add_edge(set, e) ;
  }

  for (int i = *(set.used_size); i < m ; i++) {
    edge e ;
    e.v1 = rand() % n ;
    e.v2 = rand() % n ;
    e.weight = (rand() % WEIGHT_MAX) + 1 ;
    err = add_edge(set, e) ;
    if (err != OK) {
      i-- ;
    }
  }

  printf("File to write : ");
  char * p_name = name;
  scanf("%s", p_name);
  FILE* f = fopen(p_name, "w") ;
  fprintf(f, "%d %d\n", n, m) ;
  for (int i = 0 ; i < m ; i++) {
    int a = set.array[i].v1 ;
    int b = set.array[i].v2 ;
    int w = set.array[i].weight ;
    fprintf(f, "%d %d %d\n", a, b, w) ;
  }

  fclose(f) ;
}
