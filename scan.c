#include "scan.h"


err_code scan_file(char* filename, edge_set* res, int* size) {
  int n = 0 ;
  int m = 0 ;
  int count, err ;
  FILE* f = fopen(filename, "r");
  count = fscanf(f, "%d%d", &n, &m) ;
  if (count == EOF) {
    return EMPTY_FILE ;
  } else if (count != 2) {
    return TOO_FEW_ITEMS ;
  }
  edge_set s = edge_set_create(m) ;
  for (int i = 0 ; i < m ; i++) {
    edge e ;
    count = fscanf(f, "%d%d%lf", &e.v1, &e.v2, &e.weight) ;
    if (count == EOF) {
      return TOO_FEW_EDGES ;
    } else if (count != 3) {
      return TOO_FEW_ITEMS ;
    }
    err = add_edge(s, e) ;
    if (err != OK) {
      return err ;
    }
  }
  *res = s ;
  *size = n ;
  fclose(f) ;
  return OK ;
}
