
/*@
        logic predicate is_even_pair(int *a, integer i, integer j) = (((a[i] ^ a[j]) & 1) == 0);
        logic integer counted_even_pairs(int *a, integer a_len, integer n) =
          \sum integer p; 0 <= p < n;
            (\sum integer q; p + 1 <= q < a_len;
              (is_even_pair(a, p, q) ? 1 : 0));
        */

/*@
  logic integer count_even_pairs_prefix(int *a, integer i, integer j) =
    \sum integer q; i + 1 <= q < j;
      (is_even_pair(a, i, q) ? 1 : 0);
*/
        
/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;
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
          loop invariant evenPairCount == counted_even_pairs(a, a_len, i);
          loop assigns i, evenPairCount;
            */
            for (int i = 0; i < a_len; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
            loop invariant 0 <= j <= a_len;
            loop invariant evenPairCount == counted_even_pairs(a, a_len, i) + count_even_pairs_prefix(a, i, j);
            loop assigns j, x, y, v, evenPairCount;
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
