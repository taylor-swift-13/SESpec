
/*@
    requires k >= 0 && k <= 1;
*/
void foo250(int k) {
    int i;
    int j;

    i = 1;
    j = 1;

    /*@
        loop invariant k >= \at(k, Pre) - (i - 1);
        loop invariant i == 1 + (\at(k, Pre) - k);
        loop assigns i, j, k;
    */
    while (unknown()) {
        i = i + 1;
        j = j + k;
        k = k - 1;
    }

    /*@ assert i + k <= 2; */
}
