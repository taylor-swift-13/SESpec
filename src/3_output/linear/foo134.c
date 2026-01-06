
void foo134() {
    int p;
    int c;
    int cl;

    p = 0;
    c = cl;

    /*@
      loop invariant p + cl == c;
      loop invariant 0 <= p <= 4;
      loop invariant cl <= c;
      loop assigns p, cl;
    */
    while(((p < 4) && (cl > 0))) {
       cl = cl - 1;
       p = p + 1;
    }

    /*@ assert ((p != 4) ==> (c < 4)); */
}
