#include "errors.h"

void fprint_error(err_code e) {
  switch (e) {
  case OK:
    return ;
    break ;

  case EXCEED_CAP: //non utilisé pour l'instant
    break ;

  case TOO_FEW_EDGES:
    printf("Error : end of file reached, too few edges in file") ;
    break ;

  case TWICE_EDGE:
    printf("Error : an edge is created twice") ; //j'aime pas ce message, à améliorer
    break ;

  case EMPTY_FILE:
    printf("Error : empty file") ;
    break ;

  case TOO_FEW_ITEMS:
    printf("Error : scanned less items than expected") ;
    break ;

  case TOO_MANY_EDGES:
    printf("Error : too many edges scanned") ;
    break ;
  }
  exit(1) ; // est ce qu'on exit vraiment ?
}
