#include <stdlib.h>
//Glibc iter-twice

struct list_t {
    struct list_t *next;
};


struct list_t *main9(struct list_t *l)
{
    struct list_t *p;
    p = l;
    /*@
    /*@ 
      loop invariant p != NULL ==> \exists struct list_t* q; 
        (q == l || \valid(q)) && \valid(q->next);
      loop invariant \exists struct list_t* q; q == p || q == NULL;
      loop assigns p;
      loop variant 0;  // No clear numeric variant since p moves by one or two steps; optional, can omit
    */
    */
    while (p) {
        p = p->next;
        if (p) {
          p = p -> next;
        }
      	else {
          return l;
        }
    }
    // @ assert l == \at(l,Pre);
    return l;
}