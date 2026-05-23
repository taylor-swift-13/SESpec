int findMissing(int * ar, int ar_len, int n);

/*@ 
  requires n <= 1 || (0 <= n && 0 <= ar_len && n <= ar_len && \valid_read(ar + (0 .. ar_len-1)));
  assigns \nothing;

  ensures n <= 1 ==> \result == 1;

  ensures n >= 2 ==> 1 <= \result <= n;

  ensures n >= 2 && (\exists integer k; 1 <= k <= n && ar[k-1] != k)
          ==> (ar[\result-1] != \result &&
               (\forall integer t; 1 <= t < \result ==> ar[t-1] == t));

  ensures n >= 2 && (\forall integer j; 1 <= j <= n ==> ar[j-1] == j) ==> \result == n;
*/
int findMissing(int * ar, int ar_len, int n) {

        int missing = 1;
        if (n == 0 || n == 1) {
            return missing;
        }
        /*@
          loop invariant 1 <= i <= n + 1;
          loop invariant (i == 1 ==> missing == 1) && (i > 1 ==> missing == i - 1);
          loop invariant \forall integer j; 1 <= j < i ==> ar[j-1] == j;
          loop assigns i, missing;
          loop variant n - i + 1;
        */
        for (int i = 1; i <= n; i++) {
            if (ar[i - 1] == i) {
                missing = i;
            } else if (ar[i - 1] != i) {
                return i;
            }
        }
        return missing;
}
