
/* no preconditions; invariants are established from initial values */

int foo319(int n, int y) {

    int ret = 1;
    int l = 1;
    if (n > y) {
        int g = n;
        n = y;
        y = g;
    }

    /*@
      loop invariant 1 <= ret <= j;
      loop invariant ret > 0;
      loop invariant n == \at(n,Here);
      loop invariant y == \at(y,Here);
      loop invariant \forall integer k; 1 <= k < j ==> !((n % k == 0) && (y % k == 0)) || k <= ret;
      loop invariant (n % ret == 0) && (y % ret == 0);
      loop invariant \exists integer k; 1 <= k < j && (n % k == 0) && (y % k == 0) ==> ret >= 1;
      loop invariant \forall integer k; 1 <= k < j && (n % k == 0) && (y % k == 0) ==> k <= ret;
      loop invariant (j > 1) ==> ((ret >= 1) && (ret < j));
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
