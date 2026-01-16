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
        /*@ 
          loop invariant u != 0 ==> \valid(t) && \valid(u);
          loop invariant u != 0 ==> t == \at(t,Pre) || t == \at(u,Pre);
          loop invariant \exists struct SNnode* p; p == x && (
            (\forall struct SNnode* q; q != p && q != NULL ==> q->tail != p)
          );
          loop assigns t, u;
          loop invariant t != NULL;
        */
        */
        while (u) {
            t = u;
            u = t->tail;
        }
        t->tail = y;
        return x;
    }
}