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
  printf("nombre de sommets : ");
  scanf("%d", &n) ; //sommets
  printf("nombre d'aretes : ");
  scanf("%d", &m) ; //aretes

  if ( n < 1 ) {
    printf("pas assez de sommets\n");
    exit(1);
  }
  if ( m < n - 1 ) {
    printf("pas assez d'aretes\n");
    exit(1);
  }
  if ( m > (n * (n - 1)) / 2) {
    printf("trop d'aretes\n");
    exit(1);
  }

  edge_set set = edge_set_create(m);
  for (int i = 1 ; i < n ; i++) {
    edge e ;
    e.v1 = i ;
    e.v2 = rand() % i ;
    e.weight = (rand() % WEIGHT_MAX) + 1 ;
    printf("%d %d %d\n", e.v1, e.v2, e.weight) ; 
    add_edge(set, e) ;
  }

  for (int i = *(set.used_size); i < m ; i++) {
    edge e ;
    e.v1 = rand() % n ;
    e.v2 = rand() % n ;
    e.weight = (rand() % WEIGHT_MAX) + 1 ;
    printf("%d %d %d\n", e.v1, e.v2, e.weight) ;
    add_edge(set, e) ;
  }

  printf("nom du fichier de sortie : ");
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
