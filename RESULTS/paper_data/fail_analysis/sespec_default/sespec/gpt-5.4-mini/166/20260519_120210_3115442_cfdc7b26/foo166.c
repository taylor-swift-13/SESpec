
/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;
           assigns PLACE_HOLDER;   
  ensures PLACE_HOLDER; 
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
              loop invariant 0 <= i <= a_len;
              loop invariant 0 <= evenPairCount <= a_len * (a_len - 1) / 2;
              loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
              loop assigns i, evenPairCount;
            */
            for (int i = 0; i < a_len; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 0 <= i <= a_len;
              loop invariant 0 <= evenPairCount <= a_len * (a_len - 1) / 2;
              loop invariant evenPairCount >= i * (i - 1) / 2;
              loop assigns i, evenPairCount;
              loop variant a_len - i;
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
