
/*@
  requires p >= 0;
  assigns \nothing;
  ensures \result == product(seed, \old(p > seed - p ? seed - p : p));
*/
int foo286(int seed, int p) {

    if (p > seed - p)
        p = seed - p;
    int b = 1;

    /*@
      loop invariant 1 <= r <= p + 1;
      loop invariant b == product(seed, r - 1);
      loop invariant p == \at(p, Pre);
      loop invariant seed == \at(seed, Pre);
      loop assigns r, b;
      loop variant p - r;
    */
    for (int r = 1; r <= p; r++) {
        b = b * (seed - r + 1) / r;
    }

    return b;
}
