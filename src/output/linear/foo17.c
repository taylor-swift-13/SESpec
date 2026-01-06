
void foo17(int n) {
    int x = 1;
    int m = 1;
    
    /*@
      loop invariant (1 < \at(n,Pre)) ==> (1 <= x <= n);
      loop invariant (1 < \at(n,Pre)) ==> (1 <= m < n);
      loop invariant (1 < \at(n,Pre)) ==> (m <= x);
      loop invariant (!(1 < \at(n,Pre))) ==> ((m == 1)&&(x == 1)&&(n == \at(n,Pre)));
      loop invariant n == \at(n,Pre);
      loop assigns x, m;
    */
    while (x < n) {
        if (unknown()) {
            m = x;
        }
        x = x + 1;
    }
    
    /*@ assert (n > 1) ==> (m < n); */
}
