

int foo377(int seed, int p) {

    if (p > seed - p)
        p = seed - p;
    int b = 1;

    /*@
      loop invariant (1 <= r && r <= \at(p,Pre)) ==> (1 <= r);
      loop invariant seed == \at(seed,Pre);
      loop invariant r >= 1;
      loop invariant (r <= \at(p,Pre)) ==> (p == \at(p,Pre) || p == \at(seed,Pre) - \at(p,Pre));
      loop invariant (r <= \at(p,Pre)) ==> ((p == \at(p,Pre) && \at(p,Pre) <= \at(seed,Pre) - \at(p,Pre))
                                         || (p == \at(seed,Pre) - \at(p,Pre) && \at(p,Pre) > \at(seed,Pre) - \at(p,Pre)));
      loop invariant (r <= \at(p,Pre)) ==> (r >= 1);
      loop invariant (r <= \at(p,Pre)) ==> (seed - r + 1 <= seed);
      loop invariant (r <= \at(p,Pre)) ==> (r != 0);

      loop invariant (r <= \at(p,Pre)) ==> (seed == \at(seed,Pre));
      loop invariant (r <= \at(p,Pre)) ==> (b >= 0);

      loop invariant (r <= \at(p,Pre)) ==> (b == 1 || r > 1);

      loop invariant (r <= \at(p,Pre)) ==> (\forall integer k; 1 <= k < r ==> k <= p);
      loop invariant \forall integer k; 1 <= k < r ==> (seed - k + 1) >= (seed - r + 1);
      loop invariant \forall integer k; 1 <= k < r ==> (seed - k + 1) >= 0;
      loop invariant seed == \at(seed,Pre);
      loop assigns r, b;
    */
    for (int r = 1; r <= p; r++) {
        b = b * (seed - r + 1) / r;
    }

    return b;
}
