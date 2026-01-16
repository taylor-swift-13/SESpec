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
    loop invariant (w == \null && v == p) || 
                   (\exists struct SNnode* cur; \exists struct SNnode* old_tail; 
                      w points to the reversed prefix of the original list p, 
                      v points to the remaining suffix of the original list after cur);
    loop invariant \forall struct SNnode* node; node is in w ==> \edge(node->tail) is in w or null;
    loop invariant \forall struct SNnode* node; node is in v ==> node is in original list starting at p and not in w;
    loop assigns w, v, t;
    */
    while (v) {
        t = v->tail;
        v->tail = w;
        w = v;
        v = t;
    }
    // @ assert p == \at(p,Pre);
    return w;
}