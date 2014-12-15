#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "edges.h"
#include "bool.h"

void quicksort(bool (*f) (int, int, edge_set), edge_set s, int* t, int start, int end) ;
void insertion(bool (*f) (int, int, edge_set), edge_set s, int* t, int start, int end) ;
int choose_pivot(bool (*f) (int, int, edge_set), edge_set s, int* t, int start, int end) ;
int partition(bool (*f) (int, int, edge_set), edge_set s, int* t, int pivot, int start, int end) ;
void swap (int* t, int a, int b) ;

#endif
