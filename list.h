#ifndef LIST_H
#define LIST_H

/* simple generic lists */

/* TODO : more generic (elem size...) */

typedef struct s_list * list;
typedef struct s_list {
    list cdr;
    void *car;
} s_list;

list nil;
list cons(void* car, list cdr);

list list_map(void* (*f)(void*), list l);
void list_iter(void (*f)(void*), list l);

void free_list(void (*free_elem)(void*), list l);

#endif
