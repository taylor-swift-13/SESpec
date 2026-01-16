#include <stdlib.h>
//Zephyr slist iter
struct sys_slist_t {
    struct sys_slist_t *next;
};

struct sys_slist_t *main12(struct sys_slist_t *l)
{
    struct sys_slist_t *p;
    p = l;
   
    /*@
    loop invariant \valid(p) || p == \null;
    loop invariant \forall struct sys_slist_t* q;;
    loop invariant \exists struct sys_slist_t* q; q == p || q == \null;
    loop invariant 0; // since p moves forward and list is finite;
    loop assigns p;
    /*@;
    (q == l || \exists struct sys_slist_t* r; r == l && (\exists int n; n >= 0 && q == \nth(r, n))) ==> \valid(q);
    */
    while (p) {
        p = p->next;
    }
    // @ assert l == \at(l,Pre);
    return l;
}