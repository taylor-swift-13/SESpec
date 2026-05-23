int roundNum(int n, int m);

/*@
  requires m != 0;
  assigns \nothing;

  behavior negative:
    assumes n < 0;
    ensures \result == -1;

  behavior nonnegative:
    assumes n >= 0;
    ensures 0 <= \result <= n;
    ensures \result % m == 0;
    ensures \forall integer k; 0 <= k <= n ==> (k % m == 0 ==> k <= \result);

  disjoint behaviors negative, nonnegative;
  complete behaviors negative, nonnegative;

  ensures (n < 0) ==> (\result == -1);
  ensures (\result == -1) ==> (n < 0);
*/
int roundNum(int n, int m) {

        /*@
          loop invariant i <= n;
          loop invariant \forall integer k; i < k && k <= n ==> k % m != 0;
          loop variant i;
        */
        for (int i = n; i >= 0; i--) {
            if (i % m == 0) {
                return i;
            }
        }
        return -1;
}
