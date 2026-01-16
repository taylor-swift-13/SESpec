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
        loop invariant u != NULL ==> t != NULL;
        loop invariant \valid(u);
        loop invariant \valid(t);
        loop invariant \forall struct SNnode* p; \reach(x, p) < \reach(u) ==> \valid(p);
        loop assigns u;
        loop assigns t;
        loop assigns t->tail;
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