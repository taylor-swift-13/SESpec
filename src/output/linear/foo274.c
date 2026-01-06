
void foo274() {
    int i;
    int k;
    int n;

    i = 0;
    k = 0;

    /*@
      loop invariant (0 < n) ==> (i <= n && k == i);
      loop invariant (0 < n) ==> (k <= n && i == k);
      loop invariant (!(0 < n)) ==> ((k == 0) && (i == 0));
      loop assigns i, k;
    */
    while (i < n) {
        i = i + 1;
        k = k + 1;
    }

    /*@ assert k >= n; */
}
