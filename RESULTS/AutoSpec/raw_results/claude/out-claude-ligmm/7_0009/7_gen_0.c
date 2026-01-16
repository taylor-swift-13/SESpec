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
    /*@ 
      loop invariant \valid_read(v) || v == \null;
      loop invariant \valid_read(w) || w == \null;
      loop invariant \forall struct SNnode* n; 
        (n != \null && \valid_read(n)) ==> 
          (\exists struct SNnode* m; m == w || m == v || \at(p, Pre) 
            && (n == m || \invpath(n, m)) );
      loop assigns v, w, t;
      loop variant \numof(\at(p, Pre)) - \numof(v) - \numof(w);
    */
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