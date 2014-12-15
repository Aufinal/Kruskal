#include "errors.h"

void ftest_error(err_code e) {
  switch (e) {
  case OK:
    return ;
    break ;

  case SAME_VERTEX:
    printf("Error : same vertices ; this is not an edge\n") ;
    break ;

  case TOO_FEW_EDGES:
    printf("Error : end of file reached, too few edges in file\n") ;
    break ;

  case TWICE_EDGE:
    printf("Error : an edge is created twice\n") ; 
    break ;

  case EMPTY_FILE:
    printf("Error : empty file\n") ;
    break ;

  case TOO_FEW_ITEMS:
    printf("Error : scanned less items than expected\n") ;
    break ;

  case TOO_MANY_EDGES:
    printf("Error : too many edges scanned\n") ;
    break ;
  }
  exit(1) ;
}
