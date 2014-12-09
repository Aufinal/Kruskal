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

/* L'idée me va mais j'ai un problème d'application : est ce qu'il faut passer
   aretes en argument à f, ou on utilise une autre méthode ?
   Dans le doute, je le considère pour l'instant "connu" par f, donc pas
   passé en argument. */
/* oui, on verra ca dans le main. en gros ca sera plus ou moins dans "l'environement" de f (bon en C y a pas de fermetures, mais bon... */

void quicksort(int (*f)(int, int),  int* t, int debut, int fin)
{
    if (fin-debut < MAX)
    {
      insertion (f, t, debut, fin) ;
    }
    else
    {
      int pivot = choixpivot (f, t, debut,fin) ;
      int pos_pivot = pivotage (f, t, pivot, debut, fin) ;
      quicksort (f, t, debut, pos_pivot) ;
      quicksort (f, t, pos_pivot+1, fin) ;
    }
}

int choixpivot(int (*f)(int,int), int* t, int debut, int fin)
{
    int mid = (debut+fin-1)/2 ;
    int a = ( f(t[fin-1], t[debut]) ) ? debut : (fin-1) ;
    int b = debut + fin - a - 1 ;
    if (f(t[a], t[mid]))
    {
      return a ;
    }
    else
    {
      return (f(t[b], t[mid])) ? mid : b ;
    }
}

int pivotage(int (*f) (int, int), int* t, int pivot, int debut, int fin)
{
    edge valpiv = t[pivot] ;
    int i = debut+1 , ipivot = debut ;
    swap (t, ipivot, pivot) ;
    for ( ; i < fin ; i++)
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

void insertion (int (*f)(int, int), int* t, int debut, int fin)
{
    int i = debut ;
    int actuel ;
    for ( ; i < fin ; i++)
    {
        actuel = t[i] ;
        int j = i-1 ;
        for ( ; j >= debut ; j--)
        {
	  if (f(t[j], actuel))
            {
                break ;
            }
            else
            {
                t[j+1] = t[j] ;
            }
        }
        t[j+1] = actuel ;
    }
}
