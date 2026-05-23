

/*@
  requires ar_len >= 0;
  requires 0 <= n <= ar_len;
  requires \valid(&ar[0] + (0..ar_len-1));
  requires \forall integer i; 0 <= i < ar_len ==> 0 <= ar[i] <= 100;
  assigns \nothing;
  ensures \forall integer k; 0 <= k < ar_len ==> ar[k] == \old(ar[k]);
  ensures n == 0 || n == 1 ==> \result == 1;
  ensures n >= 2 && (\exists integer i; 1 <= i <= n && ar[i-1] != i) ==> ar[\result - 1] != \result;
  ensures n >= 2 && (\exists integer i; 1 <= i <= n && ar[i-1] != i)
          ==> (\forall integer j; 1 <= j < \result ==> ar[j-1] == j);
*/
int foo239(int * ar, int ar_len, int n) {

        int missing = 1;
        if (n == 0 || n == 1) {
            return missing;
        }
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant \forall integer k; 0 <= k < ar_len ==> ar[k] == \at(ar[k], Pre);
          loop invariant \forall integer j; 1 <= j < i ==> ar[j - 1] == j;
          loop invariant (i > 1) ==> (missing == i - 1);
          loop invariant \forall integer j; (j < 1 || j >= i) ==> \true;
          loop invariant (i <= n) ==> (ar[i - 1] == i || \true);
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
