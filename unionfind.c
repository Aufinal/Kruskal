#include "unionfind.h"

void uf_reset(uf u) {
  int i ;
  for (i = 0 ; i < u.size ; i++) {
    u.tab[i] = i ;
    u.len[i] = 1 ;
  }
}

uf uf_create(int size) {
  uf u ;
  u.size = size ;
  u.tab = calloc(size, sizeof(int)) ;
  u.len = calloc(size, sizeof(int)) ;
  uf_reset(u) ;
  return u ;
}

/* fonction definies pour plus de clarté,
   inlinées pour ne pas perdre en performance */

inline int father(uf u, int x) {
  return u.tab[x] ;
}

inline void set_father(uf u, int x, int y) {
  u.tab[x] = y ;
}

inline int length(uf u, int x) {
  return u.len[x] ;
}

inline void set_lenght(uf u, int x, int i) {
  u.len[x] = i ;
}

int simple_find(uf u, int x) {
  if (x == father(u, x)) {
    return x ;
  } else {
    simple_find(u, father(u, x)) ;
  }
}

void compress(uf u, int x, int r) {
  if (x != father(u, x)) {
    set_father(u, x, r) ;
    compress(u, father(u, x), r) ;
  }
}

int uf_find(uf u, int x) {
  int r = simple_find(u, x) ;
  compress(u, x, r) ;
  return r ;
}
