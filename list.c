#include "list.h"
#include <stdlib.h>

list nil = NULL;

list cons(void* car, list cdr) {
  list l = malloc(sizeof(s_list));
  l->car = car;
  l->cdr = cdr;
  return l;
}

list list_map(void* (*f)(void*), list l) {
  /* TODO : in place */
  if (l == nil) {
    return nil;
  } else {
    return cons(f(l->car), list_map(f, l->cdr));
  }
}

void list_iter(void (*f)(void*), list l) {
  if (l != nil) {
    f(l->car);
    list_iter(f, l->cdr);
  }
}

void free_list(void (*free_elem)(void*), list l) {
  if (l != nil) {
    list rest = l->cdr;
    free_elem(l->car);
    free(l);
    free_list(free_elem, rest);
  }
}
