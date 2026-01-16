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
    loop invariant p == NULL || \valid(p);
    loop invariant p != NULL ==> \exists struct list_t* q;;
    loop invariant \length(l) - \distance(l, p);
    loop assigns p;
    \reachable(l, q) && q == p;
    /*@;
    */
    while (p) {
        p = p->next;
    }
    // @ assert l == \at(l,Pre);
    return l;
}