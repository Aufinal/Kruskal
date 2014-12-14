#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "edges.h"
#include "errors.h"

const int WEIGHT_MAX = 1500 ;

int main () {
  srand(time(NULL)) ;
  int n, m ; 
  scanf("%d\t", &n) ; //sommets
  scanf("%d", &m) ; //aretes
  FILE* f = fopen("fichier_test.txt", "w") ; //TODO : changer le nom du fichier sachant que c'est un const char*...
  fprintf(f, "%d %d\n", n, m) ;
  
  int i=0, a, b, c ;
  edge_set set = edge_set_create(m) ;
  edge e ; //à modifier si e est un "pointeur"

  while (i<m) {
    a = rand() % n ;
    do {
      b = rand() % n ;
    } while (a == b) ;
    c = (rand() % WEIGHT_MAX) + 1 ;

    e.v1 = a ;
    e.v2 = b ;
    e.weight = c ;
    if (!(edge_set_is_in(set, e))) {
      add_edge(set,e) ; // ajouter le print_error !
      fprintf(f, "%d %d %d\n", a, b, c) ;
      i++ ;
    }
  }
  fclose(f) ;
}
