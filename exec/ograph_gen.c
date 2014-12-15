#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "oedges.h"
#include "errors.h"

const double WEIGHT_MAX = 1500 ;

double rand_w() {
  double x = ((double)rand()/(double)RAND_MAX);
  return x * WEIGHT_MAX;
}

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
  if ( m > n * n) {
    printf("Too many edges\n");
    exit(1);
  }

  err_code err ;

  oedge_set set = oedge_set_create(m);

  for (int i = 0 ; i < m ; i++) {
    oedge e ;
    e.v1 = rand() % n ;
    e.v2 = rand() % n ;
    e.weight = rand_w() ;
    err = add_oedge(set, e) ;
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
    double w = set.array[i].weight ;
    fprintf(f, "%d %d %lf\n", a, b, w) ;
  }

  fclose(f) ;
}
