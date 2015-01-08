#include "mst.h"
#include <math.h>
#include <time.h>

const int X_MAX = 20000.0 ;

int test_edge (edge e, int* visited, int curr_pos) {
  int test_v1 = (e.v1 == curr_pos) && (!(visited[e.v2])) ;
  int test_v2 = (e.v2 == curr_pos) && (!(visited[e.v1])) ;
  if (test_v1) { 
    return e.v2 ;
  } else if (test_v2) {
    return e.v1 ;
  } else {
    return -1 ;
  }
}

int sum (int* t, int size) {
  int s=0 ;
  for (int i=0 ; i<size ; i++) {
    s += t[i];
  }
  return s ;
}

void journey (edge_set s, int size, int* visited, int* path, int curr_pos, double* weight) {
  path[sum(visited, size)] = curr_pos ;
  visited[curr_pos] = 1 ;
  int test = 0 ;
  for (int i=0 ; i<size - 1 ; i++) {
    edge e = s.array[i] ;
      test = test_edge(e, visited, curr_pos) ;
    if (test != -1) {
      *(weight) += s.array[i].weight ;
      journey(s, size, visited, path, test, weight) ;
    }
  }
  return ;
}


int main () {
  int n,m ;
  printf ("Nombre de sommets ?  ") ;
  scanf("%d", &n) ;
  printf("Nombre d'aretes ?  ");
  scanf("%d", &m) ;

  if ( n < 1 ) {
    printf("Not enough vertices\n");
    exit(1);
  }
  if ( m < n - 1 ) {
    printf("Not enough edges\n");
    exit(1);
  }
  if ( m > (n * (n - 1)) / 2) {
    printf("Too many edges\n");
    exit(1);
  }
  
  
  int* t_x = calloc (n, sizeof(int)) ;
  int* t_y = calloc (n, sizeof(int)) ;

  for (int i=0 ; i<n ; i++) {
    t_x[i] = rand() % X_MAX ;
    t_y[i] = rand() % X_MAX ;
  }


  err_code err ;

  srand(time(NULL)) ;
  
  edge_set set = edge_set_create(m); 
  for (int i = 1 ; i < n ; i++) { 
    edge e ;
    e.v1 = i ;
    e.v2 = rand() % i ; 
    e.weight = hypot((double)(t_x[e.v1]-t_x[e.v2]), (double)(t_y[e.v1]-t_y[e.v2])) ;
    add_edge(set, e) ;
  }

  for (int i = *(set.used_size); i < m ; i++) {
    edge e ;
    e.v1 = rand() % n ;
    e.v2 = rand() % n ;
    double cote1 = (double)(t_x[e.v1]-t_x[e.v2]);
    double cote2 = (double)(t_y[e.v1]-t_y[e.v2]);
    e.weight = sqrt(cote1*cote1 + cote2*cote2) ;
    err = add_edge(set, e) ;
    if (err != OK) {
      i-- ;
    }
  }

  edge_set mst = mst_calc(set, n) ;
  for (int i=0 ; i<n - 1 ; i++)  {
    printf("%d %d %f\n", mst.array[i].v1, mst.array[i].v2, mst.array[i].weight) ;
  }

  int start_pos ;
  printf("Starting point ?  ") ;
  scanf("%d", &start_pos) ;
  if (start_pos < 0 || start_pos >= n) {
    printf("Position outside of range") ;
    exit(1) ;
  }

  int* path = calloc(n, sizeof(int)) ;
  int* visited = calloc(n, sizeof(int)) ;
  double tot_w = 0 ;

  journey (mst, n, visited, path, start_pos, &tot_w) ;

  printf("Path to follow : \n") ;
  for (int i=0 ; i<n ; i++) {
    printf("%d  ", path[i]) ;
  }
  printf("\n Total weight : %lf\n ", tot_w) ;

}
