#ifndef UNIONFIND_H
#define UNIONFIND_H

typedef struct s_uf {
  int size ;
  int* tab ;
  int* len ;
} uf ;

uf uf_create(int size) ;

uf uf_free(uf u) ;

void uf_union(uf u, int i, int j) ;

int uf_find(uf u, int i) ;

void uf_reset(uf u) ;

#endif
