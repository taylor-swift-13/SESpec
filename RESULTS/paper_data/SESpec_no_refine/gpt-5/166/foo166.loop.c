
/*@
  logic integer cnt_even_xor_pairs_prefix(int* a, integer n) =
    n <= 0 ? 0
           : cnt_even_xor_pairs_prefix(a, n - 1)
             + (\sum(integer k = 0; k < n - 1; k++)
                  ( (((a[n - 1] ^ a[k]) & 1) == 0) ? 1 : 0 ));
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
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= a_len;
          loop invariant evenPairCount == cnt_even_xor_pairs_prefix(a, i);
          loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
          loop assigns i, j, x, y, v, evenPairCount;
            */
            for (int i = 0; i < a_len; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant i + 1 <= j <= a_len;
          loop invariant evenPairCount ==
            cnt_even_xor_pairs_prefix(a, i)
            + \sum(integer k = i + 1; k < j; k++)
                ( (((a[i] ^ a[k]) & 1) == 0) ? 1 : 0 );
          loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
          loop assigns i, evenPairCount;
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
