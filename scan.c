#include "scan.h"

// Faudrait pas mettre en argument de scan_file le nom du fichier plutôt que le fichier lui-meme ? Et mettre fopen/fclose dans la fonction...

edge_set scan_file(FILE* f) {
  // TODO : gestion des erreurs de scanf et add_edge (fait, à vérifier)
  // TODO : check pas deux fois la meme arete
  //        ex 1 2 puis 2 1 (peut-etre après le tri, ça évite un O(n^2))
  // Dans ce cas, on renvoie une erreur ou on supprime une des 2 et on diminue n ?
  int n = 0 ;
  int m = 0 ;
  int count ;
  count = fscanf(f, "%d%d", &n, &m) ;
  scan_check(count, 2) ;
  edge_set s = edge_set_create(m) ;
  for (int i = 0 ; i < m ; i++) {
    edge e ;
    count = fscanf(f, "%d%d%d", &e.v1, &e.v2, &e.weight) ;
    scan_check(count, 3) ;
    add_edge(s, e) ;
  }
  return s ;
}


void scan_check (int count, int expected) {
  if (count == EOF) {
    printf("Error : reached end of file, too few edges or file empty") ;
    exit(1) ;
  }
  if (count != expected) {
    printf("Error : %d items expected, matched only %d",expected,count) ;
    exit(1) ;
  }
}
