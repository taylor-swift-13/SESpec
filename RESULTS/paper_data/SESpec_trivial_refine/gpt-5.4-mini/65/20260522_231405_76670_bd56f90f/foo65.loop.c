
void foo65(int k) {

    int n;
    int i;

    n = 0;
    i = 0;

    /*@
      loop invariant n >= 0;
      loop invariant i >= 0;
      loop invariant 2 * n == i || 2 * n == i + 1;
      loop assigns i, n;
    */
    while (i < 2 * k) {
        if (i % 2 == 0) {
            n = n + 1;
        }
        i = i + 1;
    }
}
