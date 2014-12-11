#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"

const int MAX = 1500 ;

//TODO ; Optimisation en place (appels récursifs quicksort)

void quicksort(bool (*f)(int, int),  int* t, int start, int end)
{
    if (end-start < MAX)
    {
      insertion (f, t, start, end) ;
    }
    else
    {
      int pivot = choose_pivot (f, t, start, end) ;
      int pos_pivot = partition (f, t, pivot, start, end) ;
      quicksort (f, t, start, pos_pivot) ;
      quicksort (f, t, pos_pivot+1, end) ;
    }
}

int choose_pivot(bool (*f)(int,int), int* t, int start, int end)
{
    int mid = (start+end-1)/2 ;
    int a = ( f(t[end-1], t[start]) ) ? start : (end-1) ;
    int b = start + end - a - 1 ;
    if (f(t[a], t[mid]))
    {
      return a ;
    }
    else
    {
      return (f(t[b], t[mid])) ? mid : b ;
    }
}

int partition(bool (*f) (int, int), int* t, int pivot, int start, int end)
{
    int valpiv = t[pivot] ;
    int i = start+1 , ipivot = start ;
    swap (t, ipivot, pivot) ;
    for ( ; i < end ; i++)
    {
      if (f(t[i], valpiv))
        {
            t[ipivot] = t[i] ;
            t[i] = t[ipivot+1] ;
            ipivot++ ;
        }
    }
    t[ipivot] = valpiv ;
    return ipivot ;
}

void swap (int* t, int a, int b)
{
    int c = t[b];
    t[b] = t[a] ;
    t[a] = c ;
}

void insertion (bool (*f)(int, int), int* t, int start, int end)
{
    int i = start ;
    int current ;
    for ( ; i < end ; i++)
    {
        current = t[i] ;
        int j = i-1 ;
        for ( ; j >= start ; j--)
        {
	  if (f(t[j], current))
            {
                break ;
            }
            else
            {
                t[j+1] = t[j] ;
            }
        }
        t[j+1] = current ;
    }
}
