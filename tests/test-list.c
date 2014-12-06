#include "list.h"
#include <stdio.h>

void print_int(int i) {
  printf("%d", i);
}

int main() {
  list l = cons(1, cons(2, nil));
  list_iter(*print_int , l);
  return 0;
}
