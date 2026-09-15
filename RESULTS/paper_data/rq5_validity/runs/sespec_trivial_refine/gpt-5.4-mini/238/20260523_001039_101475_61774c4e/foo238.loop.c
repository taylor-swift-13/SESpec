
/*@
*/

/*@
  requires a_len >= 0;
  requires a_len == 0 || \valid_read(a + (0 .. a_len - 1));
*/

int foo238(int * a, int a_len, int n) {

        int count = 0;
        int length = a_len;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= length;
          loop invariant count >= 0;
          loop assigns i, count, j;
          loop variant length - i;
            */
            for (int i = 0; i < length; i++) {
            
            
        
            /*@
          loop invariant 0 <= i <= length;
          loop invariant i + 1 <= j <= length;
          loop invariant count >= 0;
          loop assigns count, j;
          loop variant length - j;
            */
            for (int j = i + 1; j < length; j++) {
                if ((a[i] ^ a[j]) % 2 == 1) {
                    count++;
                }
            }
            
        }
            
        return count;
}
