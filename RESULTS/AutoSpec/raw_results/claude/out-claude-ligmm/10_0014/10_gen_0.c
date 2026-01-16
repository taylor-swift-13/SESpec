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
        loop invariant t != NULL;
        loop invariant u == t->next;
        loop invariant \exists struct sys_slist_t* p; 
          (p == t || \exists struct sys_slist_t* q; q != NULL && p == q->next) && p != NULL;
        loop invariant \forall struct sys_slist_t* node; reachable from x until t ==> node != NULL;
        loop assigns t, u;
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