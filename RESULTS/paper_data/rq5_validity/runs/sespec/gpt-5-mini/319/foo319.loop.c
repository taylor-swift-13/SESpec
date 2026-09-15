
/* No top-level logic/predicate needed for these invariants */

/* Note: explanatory comments are regular C comments outside ACSL blocks. */

int foo319(int n, int y) {

    int ret = 1;
    int l = 1;
    if (n > y) {
        int g = n;
        n = y;
        y = g;
    }
    
    /*@

      loop invariant \forall integer d; 1 <= d < j ==> ((n % d == 0 && y % d == 0) ==> d <= ret);
      loop invariant (\exists integer d; 1 <= d && d < j && n % d == 0 && y % d == 0) ==> (ret >= 1 && n % ret == 0 && y % ret == 0);
      loop invariant (ret >= 1) ==> (n % ret == 0 && y % ret == 0) || ret == 1;

      loop invariant l == 1;

      loop invariant \forall integer d; 1 <= d && d <= j-1 ==> ((n % d == 0 && y % d == 0) ==> d <= ret);
      loop invariant (n % ret == 0 && y % ret == 0);

      loop assigns j, ret;
    */
    for (int j = 1; j <= n; j++) {
        if (n % j == 0 && y % j == 0) {
            ret = j;
        }
    }
        
    l = (n * y) / ret;
    return l;
}
