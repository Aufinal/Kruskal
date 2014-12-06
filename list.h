#ifndef LIST_H
#define LIST_H

/* simple generic lists */

/* TODO : more generic (elem size...) */

typedef struct s_list * list;
typedef struct s_list {
    list cdr;
    int car;
} s_list;

list nil;
list cons(int car, list cdr);

list list_map(int (*f)(int), list l);
void list_iter(void (*f)(int), list l);

void free_list(list l);

#endif
