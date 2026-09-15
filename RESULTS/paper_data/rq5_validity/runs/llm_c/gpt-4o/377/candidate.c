/*@
    requires seed >= 0;
    requires p >= 0 && p <= seed;
    ensures \result >= 1;
    assigns \nothing;
*/
int binomialCoeff(int seed, int p);

int binomialCoeff(int seed, int p) {

    if (p > seed - p)
        p = seed - p;
    int b = 1;
    /*@
        loop invariant 1 <= r <= p + 1;
        loop invariant b >= 1;
        loop invariant \forall integer k; 1 <= k < r ==> b == (\prod integer j; 1 <= j < k; (seed - j + 1) / j);
        loop assigns r, b;
        loop variant p - r;
    */
    for (int r = 1; r <= p; r++) {
        b = b * (seed - r + 1) / r;
    }
    return b;
}
