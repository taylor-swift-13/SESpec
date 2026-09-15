/*@
    requires num >= 0;
    requires p >= 0 && p <= num;
    ensures \result >= 0;
    assigns \nothing;
*/
int binomialCoeff(int num, int p);

int binomialCoeff(int num, int p) {

    if (p > num - p)
        p = num - p;
    int b = 1;
    /*@
        loop invariant 1 <= r <= p + 1;
        loop invariant b >= 1;
        loop assigns r, b;
        loop variant p - r;
    */
    for (int r = 1; r <= p; r++) {
        b = b * (num - r + 1) / r;
    }
    return b;
}
