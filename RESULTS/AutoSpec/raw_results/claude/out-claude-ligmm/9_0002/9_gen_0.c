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
    loop invariant \valid_read(l);
    loop invariant \valid_read(p) || p == NULL;
    loop invariant (\exists struct list_t* q; q == p) ==> (q == NULL || \valid_read(q));
    loop invariant \forall struct list_t* q; (\reach(l, q) && q != NULL) ==> q->next != NULL || p == NULL || p == q->next;
    loop assigns p;
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