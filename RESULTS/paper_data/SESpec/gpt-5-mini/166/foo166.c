
/*@
        predicate valid_array(int *a, int a_len) = a != \null && a_len >= 0;
        */

/*@
  logic integer pair_even_count(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : pair_even_count(a, lo, hi - 1)
               + (\sum integer k = lo; k <= hi-2; (((a[hi-1] ^ a[k]) & 1) == 0) ? 1 : 0);
*/

/*@ 
    requires \valid(&a[0] + (0..a_len-1));
    requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
    requires a_len > 0;
    requires a_len < 100;
    assigns \nothing;
    ensures (a == \null) ==> \result == -1;
    ensures a != \null && a_len == 1 ==> \result == 0;
    ensures a != \null && a_len > 1 ==>
             \result == (\sum integer i = 0; i <= a_len-2;
                            (\sum integer j = i+1; j <= a_len-1;
                                (((a[i] ^ a[j]) & 1) == 0) ? 1 : 0));
*/
int foo166(int * a, int a_len, int n) {

        if (a == NULL) {
            return -1;
        }
        if (a_len == 1) {
            return 0;
        }

        int evenPairCount = 0;
        
            
        /*@
            loop invariant 0 <= i <= a_len;
            loop invariant 0 <= evenPairCount <= (\sum integer p = 0; p <= a_len-2;
                                                      (\sum integer q = p+1; q <= a_len-1;
                                                          (((a[p] ^ a[q]) & 1) == 0) ? 1 : 0));
            loop invariant \forall integer k; 0 <= k < a_len ==> 0 <= a[k] <= 100;
            loop assigns i, j, x, y, v, evenPairCount;
            */
            for (int i = 0; i < a_len; i++) {
            
            
        /*@
            loop invariant 0 <= i <= a_len;
            loop invariant 0 <= evenPairCount;
            loop invariant evenPairCount == (\sum integer p = 0; p <= i-1;
                                               (\sum integer q = p+1; q <= a_len-1;
                                                   (((a[p] ^ a[q]) & 1) == 0) ? 1 : 0));
            loop assigns i, evenPairCount, a[0..a_len-1];
            */
            for (int j = i + 1; j < a_len; j++) {
                int x = a[i];
                int y = a[j];
                int v = x ^ y;
                if ((v & 1) == 0) {
                    evenPairCount++;
                }
            }
            
        }
            
        return evenPairCount;
}
