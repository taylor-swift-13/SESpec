
/*@ 
  predicate all_prefix_match(int* a, integer i) =
    \forall integer k; 1 <= k < i ==> a[k-1] == k;
*/

/*@
  requires \valid_read(ar + (0..ar_len-1));
  requires ar_len >= n;
  requires n >= 0;
  assigns \nothing;
  ensures (n == 0 || n == 1) ==> \result == 1;
               (\forall integer j; 1 <= j && j < i ==> \at(ar[j-1], Pre) == j) && \result == i)
             || (\forall integer j; 1 <= j && j <= n ==> \at(ar[j-1], Pre) == j && \result == n));
*/
int foo98(int * ar, int ar_len, int n) {

        int missing = 1;
        if (n == 0 || n == 1) {
            return missing;
        }
        
        /*@
          loop invariant 1 <= i <= n + 1;
          loop invariant \forall integer k; 1 <= k < i ==> ar[k-1] == k;
          loop invariant \forall integer k; 0 <= k < ar_len ==> ar[k] == \at(ar[k], Pre);
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
