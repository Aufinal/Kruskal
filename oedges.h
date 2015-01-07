#ifndef OEDGES_H
#define OEDGES_H

#include "errors.h"
#include "bool.h"

typedef struct s_oedge {
  double weight ;
  int v1 ;
  int v2 ;
} oedge ;

bool oedge_eq(oedge e1, oedge e2) ;

typedef struct s_oedge_set {
  int max_size ;
  int* used_size ;
  oedge* array ;
} oedge_set ;

oedge_set oedge_set_create(int max_size) ;
err_code add_oedge(oedge_set set, oedge e) ;
bool oedge_set_is_in(oedge_set set, oedge e) ;

#endif // OEDGES_H
