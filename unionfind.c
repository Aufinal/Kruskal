#include <stdlib.h>
#include "unionfind.h"

void uf_reset(uf u) {
  int i ;
  for (i = 0 ; i < u.size ; i++) {
    u.father[i] = i ;
    u.rank[i] = 0 ;
  }
}

uf uf_create(int size) {
  uf u ;
  u.size = size ;
  u.father = calloc(size, sizeof(int)) ;
  u.rank = calloc(size, sizeof(int)) ;
  uf_reset(u) ;
  return u ;
}

void uf_free(uf u) {
  free(u.father) ;
  free(u.rank) ;
}

int simple_find(uf u, int x) {
  if (x == u.father[x]) {
    return x ;
  } else {
    return simple_find(u, u.father[x]) ;
  }
}

void compress(uf u, int x, int r) {
  int y = u.father[x] ;
  if (x != y) {
    u.father[x] = r ;
    compress(u, y, r) ;
  }
}

int uf_find(uf u, int x) {
  int r = simple_find(u, x) ;
  compress(u, x, r) ;
  return r ;
}

void uf_union(uf u, int x, int y) {
  int r1 = uf_find(u, x) ;
  int r2 = uf_find(u, y) ;
  if (r1 != r2 ) {
    if (u.rank[r1] < u.rank[r2]) {
      u.father[r1] = r2 ;
    } else if (u.rank[r1] > u.rank[r2]) {
      u.father[r2] = r1 ;
    } else {
      u.father[r2] = r1 ;
      u.rank[r1] += 1 ;
    }
  }
}
