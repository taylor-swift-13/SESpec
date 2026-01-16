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
    loop invariant \valid_read(p);
    loop invariant \forall struct SNnode* q; \at(p, Pre) != NULL && (q == \at(p, Pre) || \exists struct SNnode* r; r == q->tail) ==> \valid_read(q);
    loop invariant \forall struct SNnode* n; n != NULL && (n == w || n == v || n == t || \exists struct SNnode* m; m == n->tail) ==> \valid(n);
    loop invariant \exists struct SNnode* q; q == w || q == v || q == t || q == p;
    loop invariant \forall struct SNnode* n; n != NULL ==> (n == w) || (n == v) || (n == t) || (n == p) || n->tail != w;
    loop invariant \forall struct SNnode* n; n != NULL ==> (n != w) ==> (n->tail != w);
    loop invariant \exists struct SNnode* head; head == w;
    loop invariant \forall struct SNnode* n; n != NULL ==> (n == w) || (n == v) || (_leftover nodes linked correctly);
    loop assigns w, v, t;
    loop assigns ((struct SNnode*)p);
    loop assigns ((struct SNnode*)w);
    loop assigns ((struct SNnode*)v);
    loop assigns ((struct SNnode*)t);
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