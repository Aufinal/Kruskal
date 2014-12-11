#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "unionfind.h"
#include "quicksort.h"
#include "edges.h"

// TODO : modifier f, etc... Faire un main quoi !

bool f(int a, int b) {
  return (a<=b) ;
}

int main()
{
/*
    int i=0,n=0,m=0 ;

    scanf("%d", &n) ; //nombre de sommets
    scanf("%d", &m) ; //nombre d'aretes

    // Initialisation des 2 tableaux : la foret de Kruskal et la liste des arêtes
    int pere[n] ,
    int* aretes [m] ;
    int a,b,c ; //Variables pour le scanf des aretes

    for(i=0 ; i<m ; i++)
     {
        printf("\n") ;
        scanf ("%d", &a) ;
        scanf ("%d", &b) ;
        scanf ("%d", &c) ;
        aretes[i]=[a,b,c] ;
    }

    for(i=0 ; i<n ; i++)
    {
        makeset(i,pere) ;
    }
*/


    srand (time(NULL)) ;
    int n = 100000, i = 0 ;
    // scanf("%d", &n) ;
    int t[n];

    for ( ; i<n ; i++)
    {
      t[i] = rand() ;
    }

    quicksort(*f, t, 0, n ) ;

    int c = 1, j=0  ;

    while (c && j < n-1)
    {
        c = t[j] <= t[j+1] ;
        j++ ;
    }

    printf("%d\n", c) ;

    return 0 ;
}
