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
    loop invariant p == NULL || (\exists struct sys_slist_t* q; \at(l,Pre) != NULL && p == q);
    loop invariant \at(l,Pre) != NULL ? (\distance_from p to NULL in the list starting at \at(l,Pre)) : 0;
    loop invariant (p == l) || (\exists struct sys_slist_t* q; \at(l,Pre) != NULL && p == q- > next);
    loop assigns p;
    */
    while (p) {
        p = p->next;
    }
    // @ assert l == \at(l,Pre);
    return l;
}