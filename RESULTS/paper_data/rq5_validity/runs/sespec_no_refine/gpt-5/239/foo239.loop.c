
/*@
  logic boolean prefix_match(int* a, integer i) =
    i <= 1 ? \true
           : (a[i-2] == (i-1) && prefix_match(a, i-1));
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
