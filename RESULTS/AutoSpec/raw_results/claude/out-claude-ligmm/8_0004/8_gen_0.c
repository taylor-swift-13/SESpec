#include <stdlib.h>
//Glibc iter

struct list_t {
    struct list_t *next;
};


struct list_t *main8(struct list_t *l)
{
    struct list_t *p;
    p = l;
    /*@
    /*@ 
      loop invariant p != NULL ==> \exists struct list_t* q; 
        \reachable(l, q) && q == p;
      loop invariant p == NULL || \valid(p);
      loop assigns p;
      loop variant \length(l) - \distance(l, p);
    */
    */
    while (p) {
        p = p->next;
    }
    // @ assert l == \at(l,Pre);
    return l;
}