
/*@
  logic boolean prefix_match(int* a, integer i) =
    i <= 1 ? \true
           : (a[i-2] == (i-1) && prefix_match(a, i-1));
*/

/*@
  requires \valid(&ar[0] + (0..ar_len-1));
  requires \forall integer i; 0 <= i < ar_len ==> 0 <= ar[i] <= 100;
  requires ar_len > 0;
  requires ar_len < 100;
  assigns \nothing;
  ensures (n == 0 || n == 1) ==> \result == 1;
  ensures n >= 1 ==> 1 <= \result;
  ensures n >= 1 ==> (
            (\exists integer j; 1 <= j <= n && ar[j-1] != j ==>
                \result == (\exists integer t; 1 <= t <= n && ar[t-1] != t ? 
                              ( \let jj = \min \lambda integer u; 1 <= u <= n && ar[u-1] != u in jj; jj ) : \result )
            )
        || (\forall integer k; 1 <= k <= n ==> ar[k-1] == k) && \result == (n == 0 ? 1 : n)
    );
  ensures n >= 1 ==> (
            (\exists integer j; 1 <= j <= n && ar[j-1] != j) ==>
                (1 <= \result <= n &&
                 ar[\result-1] != \result &&
                 (\forall integer k; 1 <= k < \result ==> ar[k-1] == k))
        );
  ensures n >= 1 && (\forall integer k; 1 <= k <= n ==> ar[k-1] == k) ==> \result == n;
*/
int foo239(int * ar, int ar_len, int n) {

        int missing = 1;
        if (n == 0 || n == 1) {
            return missing;
        }
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= missing <= i;
          loop invariant prefix_match(ar, i);
          loop invariant missing == (prefix_match(ar, i) ? (i-1 >= 1 ? i-1 : 1) : missing);
          loop invariant \forall integer k; 0 <= k < (i-1) ==> ar[k] == (k+1);
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
