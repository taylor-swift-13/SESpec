
/*@
  logic integer seq_count(integer lo, integer hi) =
    lo >= hi ? 0 : seq_count(lo, hi-1) + 1;
*/

/* Note: no additional top-level logic required */

/*@
  requires n >= 0;
*/

int foo158(int n) {

        if (n <= 2) {
            return n;
        }
        int i = n * 2;
        int *factors = (int *)malloc(sizeof(int) * (n));
int factors_len = n;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (j < n) ==> (\forall integer k; 0 <= k < j ==> factors[k] == k + 1);
          loop invariant (!(j < n)) ==> \true;
          loop invariant \forall integer k; 0 <= k < n ==>
                            (k < j ? factors[k] == k + 1 : \true);
          loop assigns j, factors[0..n-1];
            */
            for (int j = 0; j < n; j++) {
            factors[j] = j + 1;
        }
            
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant  \true ;
          loop invariant \forall integer k; 0 <= k < n ==> factors[k] == k + 1;
            */
            while (1) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant \forall integer k; 0 <= k < n ==> factors[k] == k + 1;
              loop invariant (0 <= a < n) ==>
                             ( (\exists integer b; 0 <= b < a && i % factors[b] != 0)
                               || (\forall integer b; 0 <= b < a ==> i % factors[b] == 0) );
              loop assigns a, i;
            */
            for (int a = 0; a < n; a++) {
                if (i % factors[a] != 0) {
                    i += n;
                    break;
                }
                if (factors[a] == factors[n - 1] && i % factors[a] == 0) {
                    return i;
                }
            }
            
        }
            
}
