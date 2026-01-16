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
    loop invariant \valid(p) || p == NULL;
    loop invariant \forall struct list_t* q; ( \exists struct list_t* r; r == l && q == r || (\exists struct list_t* s; s == q->next && \valid(s)) ) ==> q != NULL;
    loop assigns p;
    loop variant /* unknown */;
    */
    while (p) {
        p = p->next;
    }
    // @ assert l == \at(l,Pre);
    return l;
}