
/*@
  assigns \nothing;
  ensures (k <= \old(n) - \old(k)) ==> k == \old(k);
  ensures n == \old(n);
  ensures (k == 0) ==> \result == 1;
*/
int foo384(int n, int k) {

    if (k > n - k)
        k = n - k;
    int c = 1;

    /*@
      loop invariant 1 <= i;
      loop invariant n == \at(n,Pre);
      loop invariant i == 1 ==> c == 1;
      loop invariant \forall integer t; 1 <= t < i ==> 1 <= t <= k;
      loop invariant \forall integer t; 1 <= t < i ==> n - t + 1 >= n - k + 1;
      loop assigns i, c;
    */
    for (int i = 1; i <= k; i++) {
        c = c * (n - i + 1) / i;
    }

    return c;
}
