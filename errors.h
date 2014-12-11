#ifndef ERRORS_H
#define ERRORS_H

#include <stdio.h>

#define OK 0
#define EXCEED_CAP 1 // à remplacer
#define TOO_FEW_EDGES 2
#define TWICE_EDGE 3
#define EMPTY_FILE 4
#define TOO_FEW_ITEMS 5
#define TOO_MANY_EDGES 6

typedef int err_code ;

void fprint_error(FILE* f, err_code e); // TODO : implem

#endif
