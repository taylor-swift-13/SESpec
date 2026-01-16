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
    loop invariant p != NULL ==> p != \null;
    loop invariant \valid(p) || p == NULL;
    loop invariant \length_list(p);
    loop invariant \forall struct list_t *q;;
    loop assigns p;
    /*@;
    (q == l || \exists struct list_t *r; r->next == q) ==> \valid(q);
    */
    while (p) {
        p = p->next;
    }
    // @ assert l == \at(l,Pre);
    return l;
}