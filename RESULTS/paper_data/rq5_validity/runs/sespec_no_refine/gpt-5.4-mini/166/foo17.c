
/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;
  assigns \nothing;
  ensures a == \null ==> \result == -1;
  ensures a != \null && a_len == 1 ==> \result == 0;
  ensures a != \null && a_len > 1 ==> 0 <= \result <= a_len * (a_len - 1) / 2;
  ensures a != \null && a_len > 1 ==> \result == \old(evenPairCount);
*/
int foo17(int * a, int a_len, int n) {

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
              loop invariant 0 <= evenPairCount <= i * (a_len - 1) - (i * (i - 1)) / 2;
              loop invariant evenPairCount >= 0;
              loop assigns i, j, x, y, v, evenPairCount;
            */
            for (int i = 0; i < a_len; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 0 <= i <= a_len;
              loop invariant 0 <= evenPairCount <= a_len * (a_len - 1) / 2;
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
