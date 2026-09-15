
/*@
  logic integer count_mismatches(int* ar, integer lo, integer hi) =
    lo >= hi ? 0
             : count_mismatches(ar, lo, hi - 1) + (ar[hi - 1] == hi ? 0 : 1);
*/

int foo98(int * ar, int ar_len, int n) {

        int missing = 1;
        if (n == 0 || n == 1) {
            return missing;
        }
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (!(i <= n)) ==> ();
          loop invariant \forall integer k; 0 <= k < ar_len ==> ar[k] == \at(ar[k], Pre);
          loop invariant 1 <= i <= n + 1;
          loop invariant 1 <= missing <= i;
          loop invariant missing == i || missing == i - 1;
          loop invariant \forall integer k; 1 <= k < i ==> (ar[k - 1] == k ==> missing >= k);
          loop assigns i, missing;
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
