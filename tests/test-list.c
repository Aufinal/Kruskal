#include "list.h"
#include <stdio.h>

void print_trash(void* i) {
  printf("%d", (int) i);
}

int main() {
  list l = cons((void*) 1, cons((void*) 2, nil));
  list_iter(*print_trash , l);
  return 0;
}
