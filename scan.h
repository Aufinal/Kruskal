#ifndef SCAN_H
#define SCAN_H

#include "edges.h"
#include <stdio.h>

edge_set scan_file(FILE* f) ;
void scan_check(int count, int expected) ;

#endif
