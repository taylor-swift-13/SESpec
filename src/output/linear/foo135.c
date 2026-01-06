
void foo135() {
    int p;
    int c;
    int cl;

    p = 0;
    c = cl;

    /*@
      loop invariant p + cl == c;
      loop invariant 0 <= p <= 4;
      loop invariant cl > 0 ==> cl >= 0;
      loop assigns p, cl;
    */
    while(p < 4 && cl > 0) {
       cl = cl - 1;
       p = p + 1;
    }

    /*@ assert (c >= 4) ==> (p == 4); */
}
