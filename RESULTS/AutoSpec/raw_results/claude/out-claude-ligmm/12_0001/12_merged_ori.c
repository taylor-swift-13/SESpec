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
    loop invariant p == \null ? 0 : 1;;
    loop invariant \valid(p) || p == \null;
    loop invariant \subset(\reach(l), p);
    loop assigns p;
    /*@;
    */
    while (p) {
        p = p->next;
    }
    // @ assert l == \at(l,Pre);
    return l;
}