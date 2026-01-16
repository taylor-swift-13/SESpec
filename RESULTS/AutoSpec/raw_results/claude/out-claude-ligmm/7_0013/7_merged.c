#include <stdlib.h>
//Sling slist reverse

struct SNnode {
    int head;
    struct SNnode *tail;
};

struct SNnode *main7(struct SNnode *p)
{
    struct SNnode *w, *t, *v;
    w = 0;
    v = p;
    
    /*@
    loop invariant \at(p, Pre) == p;
    */
    while (v) {
        t = v->tail;
        v->tail = w;
        w = v;
        v = t;
    }
    //@ assert p == \at(p,Pre);
    return w;
}