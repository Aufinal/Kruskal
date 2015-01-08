#ifndef UNIONFIND_H
#define UNIONFIND_H

typedef struct s_uf {
  int size ;
  int* father ;
  int* rank ; /* heuristique pour l'algorithme */
} uf ;

uf uf_create(int size) ;

void uf_free(uf u) ;

void uf_union(uf u, int x, int y) ;

int uf_find(uf u, int x) ;

void uf_reset(uf u) ;

#endif
