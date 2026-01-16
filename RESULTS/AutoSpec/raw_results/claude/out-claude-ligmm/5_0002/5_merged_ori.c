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
        loop invariant u != NULL ==> (\exists struct SNnode* p; u == p && p->tail == u->tail);
        loop invariant t != NULL && (t == x || (\exists struct SNnode* p; p- > tail == t));
        loop invariant \valid(t);
        loop invariant \distance(u, NULL);
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