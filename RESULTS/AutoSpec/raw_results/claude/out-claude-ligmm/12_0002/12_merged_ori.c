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
    loop invariant p;
    loop invariant p == \at(p,Pre) || \exists struct sys_slist_t* q; q == \at(l,Pre) && (\forall struct sys_slist_t* r; (r != NULL && r != p) ==> r->next != NULL);
    loop invariant \valid(l);
    loop invariant \forall struct sys_slist_t* q; \at(l,Pre) != NULL ==> (\exists struct sys_slist_t* r; q == r->next);
    loop assigns p;
    */
    while (p) {
        p = p->next;
    }
    // @ assert l == \at(l,Pre);
    return l;
}