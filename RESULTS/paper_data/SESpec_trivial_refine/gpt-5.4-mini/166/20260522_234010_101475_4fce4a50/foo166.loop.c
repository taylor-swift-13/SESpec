
/*@
PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
*/

/*@ 
  requires a_len == 0 || \valid_read(a + (0 .. a_len - 1));
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
          loop invariant evenPairCount >= 0;
            */
            for (int i = 0; i < a_len; i++) {
        
        
    /* >>> LOOP INVARIANT TO FILL <<< */
    
        /*@
          loop invariant 0 <= j <= a_len;
          loop invariant evenPairCount >= 0;
          loop assigns evenPairCount;
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
