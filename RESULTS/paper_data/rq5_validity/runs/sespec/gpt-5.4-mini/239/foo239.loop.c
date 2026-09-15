
/*@
  logic integer count_matching_prefix(int *ar, integer i) =
    i <= 1 ? 0 :
    count_matching_prefix(ar, i - 1) + (ar[i - 2] == i - 1 ? 1 : 0);
*/

int foo239(int * ar, int ar_len, int n) {

        int missing = 1;
        if (n == 0 || n == 1) {
            return missing;
        }
        
        /*@
          loop invariant 1 <= i;
          loop invariant 1 <= missing <= i;
          loop invariant (i == 1 ==> missing == 1);
          loop invariant (i > 1 ==> missing == i - 1);
          loop invariant \forall integer k; 1 <= k < i ==> ar[k - 1] == k;
          loop invariant \forall integer k; 1 <= k < i ==> missing >= k;
          loop invariant (i > n) ==> \forall integer k; 1 <= k <= n ==> ar[k - 1] == k;
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
