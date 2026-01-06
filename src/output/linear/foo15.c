
void foo15(int n) {
    int x = 0;
    int m = 0;

    /*@
      loop invariant x >= 0;
      loop invariant x <= \max(0,n);
      loop invariant m >= 0;
      loop invariant m < x || (x == 0 && m == 0);
      loop invariant m < n || n <= 0;
      loop invariant n == \at(n,Pre);
      loop assigns x, m;
    */
    while (x < n) {
        if (unknown()) {
            m = x;
        }
        x = x + 1;
    }

    /*@ assert (n > 0) ==> (m < n); */
}
