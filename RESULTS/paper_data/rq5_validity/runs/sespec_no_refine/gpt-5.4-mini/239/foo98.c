
/*@
  logic integer count_mismatches(int* ar, integer lo, integer hi) =
    lo >= hi ? 0
             : count_mismatches(ar, lo, hi - 1) + (ar[hi - 1] == hi ? 0 : 1);
*/

/*@
  requires \valid(&ar[0] + (0..ar_len-1));
  requires \forall integer i; 0 <= i < ar_len ==> 0 <= ar[i] <= 100;
  requires ar_len > 0;
  requires ar_len < 100;
  assigns \nothing;
  ensures n == 0 || n == 1 ==> \result == 1;
  ensures n > 1 && (\forall integer i; 1 <= i <= n ==> ar[i - 1] == i) ==> \result == n;
  ensures n > 1 && (\exists integer i; 1 <= i <= n && ar[i - 1] != i && (\forall integer j; 1 <= j < i ==> ar[j - 1] == j)) ==> \result == i;
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
