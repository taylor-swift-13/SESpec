
int foo385(int n, int m) {

    /*@
      loop invariant i <= n;
      loop invariant \forall integer k; i < k <= n ==> k % m != 0;
      loop invariant m == \at(m,Pre);
      loop invariant n == \at(n,Pre);
      loop assigns i;
    */
    for (int i = n; i >= 0; i--) {
        if (i % m == 0) {
            return i;
        }
    }

    return -1;
}
