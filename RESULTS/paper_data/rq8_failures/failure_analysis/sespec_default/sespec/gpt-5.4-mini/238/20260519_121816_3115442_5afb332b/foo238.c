
        /*@
        */
        
/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;
  assigns \nothing;
  ensures \result == \numof(integer ii, integer jj, 0 <= ii < a_len && ii < jj < a_len && ((a[ii] ^ a[jj]) % 2 == 1));
*/

int foo238(int * a, int a_len, int n) {

        int count = 0;
        int length = a_len;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= length;
          loop invariant 0 <= count;
          loop invariant count <= length * (length - 1) / 2;
          loop invariant count == \numof(integer ii, integer jj, 0 <= ii < i && ii < jj < length && ((a[ii] ^ a[jj]) % 2 == 1));
          loop assigns i, count, j;
            */
            for (int i = 0; i < length; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 0 <= i <= length;
              loop invariant 0 <= count;
              loop assigns i, count, j;
            */
            for (int j = i + 1; j < length; j++) {
                if ((a[i] ^ a[j]) % 2 == 1) {
                    count++;
                }
            }
            
        }
            
        return count;
}
