
/*@
*/

/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  assigns \nothing;
  ensures (a == \null) ==> \result == -1;
  ensures (a != \null && a_len == 1) ==> \result == 0;
  ensures (a != \null && a_len >= 0) ==> \forall integer k; 0 <= k < a_len ==> a[k] == \old(a[k]);
  ensures (a != \null && a_len >= 0) ==> \result >= 0;
  ensures (a != \null && a_len >= 0) ==> \result == (\sum integer i1, j1; 0 <= i1 < j1 < a_len; (((a[i1] ^ a[j1]) & 1) == 0) ? 1 : 0);
  ensures \result == PLACE_HOLDER_RESULT;
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
          loop invariant 0 <= evenPairCount;
          loop invariant 0 <= a_len;
          loop invariant \forall integer k; 0 <= k < a_len ==> 0 <= a[k] <= 100;
          loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
          loop invariant 0 <= i <= a_len;
          loop invariant \forall integer p,q; 0 <= p < i && p+1 <= q < a_len ==> ((a[p] ^ a[q]) & 1) == ((a[p] ^ a[q]) % 2);
          loop invariant \forall integer p; 0 <= p < i ==> \exists integer t; p+1 <= t <= a_len;
          loop assigns i, j, x, y, v, evenPairCount;
            */
            for (int i = 0; i < a_len; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= a_len;
          loop invariant evenPairCount >= 0;
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
