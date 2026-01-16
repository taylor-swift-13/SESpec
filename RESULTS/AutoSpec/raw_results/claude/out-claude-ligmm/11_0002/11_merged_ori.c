#include <stdlib.h>
//Zephyr slist itertwice

struct sys_slist_t {
    struct sys_slist_t *next;
};


struct sys_slist_t *main11(struct sys_slist_t *l)
{
    struct sys_slist_t *p;
    p = l;
   
    /*@
    loop invariant (p == NULL) || (\exists int k >= 0; p == \nth(l, 2*k));
    loop invariant (\forall struct sys_slist_t* q; \reachable(l, q) ==> (\exists int m; m >= 0 && \at(q, Here) == \at(q, Pre)));
    loop assigns p;
    loop assigns \nothing;
    */
    while (p) {
        p = p->next;
        if (p) {
          p = p -> next;
        }
    }
    // @ assert l == \at(l,Pre);
    return l;
}