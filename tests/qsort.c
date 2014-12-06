#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "unionfind.h"
#include "quicksort.h"
#include "aretes.h"

/* en fait ce fichier a plus ca place dans le dossier tests
   avec le Makefile ca te fait tout bien ... */
/* par contre faudrait faire un fichier read_file.c dans le dossier principal */
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
    int n = 1000000, i = 0 ;
    // scanf("%d", &n) ;

    edge t[n];
    int a ;


    for ( ; i<n ; i++)
    {
        a = rand () % 1000 ;
        t[i].weight = a ;
    }

    quicksort(t, 0, n) ;

    int c = 1, j=0  ;

    while (c && j < n-1)
    {
        c = t[j].weight <= t[j+1].weight ;
        j++ ;
    }


    return 0 ;
}
