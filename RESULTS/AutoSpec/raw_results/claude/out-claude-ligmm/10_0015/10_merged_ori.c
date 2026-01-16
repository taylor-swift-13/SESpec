#include <stdlib.h>
//Zephyr slist append

struct sys_slist_t {
    struct sys_slist_t *next;
};


struct sys_slist_t * main10(struct sys_slist_t * x, struct sys_slist_t * y)
{
    struct sys_slist_t *t, *u;
    if (x == 0) {
        // @ assert x == \at(x,Pre);
        // @ assert y == \at(y,Pre);
        return y;
    } else {
        t = x;
        u = t->next;
        /*@
        loop invariant u != NULL || t- > next == NULL;
        loop invariant \valid(t);
        loop invariant \forall struct sys_slist_t* p; (p == x || \exists struct sys_slist_t* q; q->next == p) ==> p != NULL;
        loop invariant \forall struct sys_slist_t* p; (p == x || \exists struct sys_slist_t* q; q->next == p ) ==> \valid(p);
        loop invariant \exists struct sys_slist_t* p; p == t && (p == x || \exists struct sys_slist_t* q; q- > next == p);
        loop invariant t != NULL;
        loop assigns u;
        loop assigns t;
        */
        while (u) {
            t = u;
            u = t->next;
        }
        // @ assert u == t->next;
        t->next = y;
        return x;
    }
}