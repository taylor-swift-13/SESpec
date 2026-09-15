
/*@
  predicate PLACE_HOLDER_b = (b == (\prod integer i; 1 <= i <= r; (seed - i + 1) / i));
*/

int foo286(int seed, int p) {

    if (p > seed - p)
        p = seed - p;
    int b = 1;

    /*@
      loop invariant (r <= \at(p,Pre)) ==> (b == (\prod integer i; 1 <= i <= r; (seed - i + 1) / i));
      loop invariant (!(r <= \at(p,Pre))) ==> ((b == 1)&&(p == \at(p,Pre))&&(seed == \at(seed,Pre)));
      loop invariant p == \at(p,Pre);
      loop invariant seed == \at(seed,Pre);
      loop assigns r, b;
    */
    for (int r = 1; r <= p; r++) {
        b = b * (seed - r + 1) / r;
    }

    return b;
}
