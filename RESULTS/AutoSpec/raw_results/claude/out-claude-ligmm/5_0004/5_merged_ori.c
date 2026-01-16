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
        loop invariant u != NULL ==> \exists struct SNnode* p; p == u && p == t->tail;
        loop invariant t != NULL;
        loop invariant \forall struct SNnode* n;;
        loop invariant 0; // assuming acyclic list, else a separate measure needed;
        loop assigns u;
        loop assigns t;
        /*@;
        (\exists struct SNnode* r; r == n || r == t) );
        ((\at(x,Pre) == n) || (\exists struct SNnode* q; q == n- > tail)) ) == >;
        ( ( \at(x,Pre) != NULL && n != NULL &&;
        */
        while (u) {
            t = u;
            u = t->tail;
        }
        t->tail = y;
        return x;
    }
}