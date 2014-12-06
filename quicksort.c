#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"

const int MAX = 1500 ;

/* En fait je pense que le quicksort comme l'union-find devrait se faire
   sur des entiers ; en parametrant par la fonction de comparaison
   pour le quicksort. On aurait un premier tableau avec toutes les aretes
   (issu du scan du fichier), qui permet d'associer a chaque entier entre
   0 et m - 1 une arete, puis on travaille avec ces entiers la (en les
   assimilant aux aretes).
   Du coup la fonction de comparaison c'est
   f(int e1, int e2) { aretes[e1].weight <= aretes[e2].weight },
   et on peut parametrer le quicksort par une fonction (int (*f)(int)) */

void quicksort(edge* aretes, int debut, int fin)
{
    if (fin-debut < MAX)
    {
        insertion (aretes,debut,fin) ;
    }
    else
    {
        int pivot = choixpivot (aretes, debut,fin) ;
        int pos_pivot = pivotage (aretes, pivot, debut, fin) ;
        quicksort (aretes, debut, pos_pivot) ;
        quicksort (aretes, pos_pivot+1, fin) ;
    }
}

int choixpivot(edge* t, int debut, int fin)
{
    int mid = (debut+fin-1)/2 ;
    int a = (t[fin-1].weight < t[debut].weight) ? debut : (fin-1) ;
    int b = debut + fin - a - 1 ;
    if (t[a].weight < t[mid].weight)
    {
        return a ;
    }
    else
    {
        return (t[b].weight < t[mid].weight) ? mid : b ;
    }
}

int pivotage(edge* aretes, int pivot, int debut, int fin)
{
    edge valpiv = aretes[pivot] ;
    int i = debut+1 , ipivot = debut ;
    swap (aretes, ipivot, pivot) ;
    for ( ; i < fin ; i++)
    {
        if (aretes[i].weight < valpiv.weight)
        {
            aretes[ipivot] = aretes[i] ;
            aretes[i] = aretes[ipivot+1] ;
            ipivot++ ;
        }
    }
    aretes[ipivot] = valpiv ;
    return ipivot ;
}

void swap (edge* t, int a, int b)
{
    edge c = t[b];
    t[b] = t[a] ;
    t[a] = c ;
}

void insertion (edge* aretes, int debut, int fin)
{
    int i = debut ;
    edge actuel ;
    for ( ; i < fin ; i++)
    {
        actuel = aretes[i] ;
        int j = i-1 ;
        for ( ; j >= debut ; j--)
        {
            if (aretes[j].weight < actuel.weight)
            {
                break ;
            }
            else
            {
                aretes[j+1] = aretes[j] ;
            }
        }
        aretes[j+1] = actuel ;
    }
}
