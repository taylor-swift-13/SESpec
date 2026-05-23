
/*@
  logic integer nCk(integer n, integer k) =
    (k <= 0) ? 1 :
    (k > n)  ? 0 :
    (nCk(n, k-1) * (n - k + 1)) / k;
*/

/*@
  requires r >= 0;
  requires \at(n,Pre) >= \at(r,Pre);
  
*/
int foo368(int n, int r, int p) {

    if (n < r) {
        return 0;
    }

    int ncr = 1;

    /*@
      loop invariant 1 <= i <= r + 1;
      loop invariant r == \at(r,Pre);
      loop invariant n == \at(n,Pre);
      loop invariant p == \at(p,Pre);

      loop invariant n >= r;
      loop invariant 0 <= r;
      loop invariant 0 <= i - 1 <= r;

      loop invariant ncr == nCk(n, i - 1);

      loop invariant \forall integer k; 0 <= k <= i - 1 ==> nCk(n, k) >= 0;

      loop invariant (i <= \at(r,Pre)) ==> (i >= 1);
      loop invariant (i <= \at(r,Pre)) ==> (ncr == nCk(n, i - 1));

      loop invariant (i == r + 1) ==> (ncr == nCk(n, r));

      loop assigns i, ncr;
    */
    for (int i = 1; i <= r; i++) {
        ncr = (ncr * (n - i + 1)) / i;
    }

    return ncr % p;
}
