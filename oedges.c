#include <stdlib.h>
#include "oedges.h"

bool oedge_eq(oedge e1, oedge e2) {
  return (e1.v1 == e2.v1) && (e1.v2 == e2.v2) ;
}

oedge_set oedge_set_create(int max_size) {
  oedge_set s ;
  s.max_size = max_size ;
  s.used_size = calloc( 1, sizeof(int)) ;
  *(s.used_size) = 0 ;
  s.array = calloc(max_size, sizeof(oedge)) ;
  return s ;
}

err_code add_oedge(oedge_set set, oedge e) {
  if (set.max_size == *(set.used_size)) {
    return TOO_MANY_EDGES ;
  } else if (oedge_set_is_in(set, e)) {
    return TWICE_EDGE ;
  } else {
    set.array[*(set.used_size)] = e ;
    *(set.used_size) += 1 ;
    return OK ;
  }
}

bool oedge_set_is_in(oedge_set set, oedge e) {
  for(int i = 0 ; i < *(set.used_size) ; i++) {
    if (oedge_eq(e, set.array[i])) {
      return TRUE ;
    }
  }
  return FALSE ;
}
