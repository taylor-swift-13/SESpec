#include <stdlib.h>
//Sling slist append


struct SNnode {
    int head;
    struct SNnode *tail;
};

struct SNnode * main5(struct SNnode * x, struct SNnode * y)

{
    struct SNnode *t, *u;
    if (x == 0) {
        // @ assert x == \at(x,Pre);
        // @ assert y == \at(y,Pre);
        return y;
    } else {
        t = x;
        u = t->tail;

        /*@
        loop invariant u != NULL ==> u == \at(u, Pre) || u == \at(u, \old(t->tail));
        loop invariant u != NULL ==> \valid(t);
        loop invariant \valid(t);
        loop invariant \forall struct SNnode* p; \at(x, Pre) != 0 && \reach(\at(x, Pre), p) && p != y ==> \reach(x, p);
        loop assigns u;
        loop assigns u->tail;
        loop assigns t;
        /*@;
        */
        while (u) {
            t = u;
            u = t->tail;
        }
        t->tail = y;
        return x;
    }
}