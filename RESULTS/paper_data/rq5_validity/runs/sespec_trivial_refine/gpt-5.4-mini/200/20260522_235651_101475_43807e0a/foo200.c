
        /*@
        */

/*@
  requires 0 <= size <= a_len;
  requires size == 0 || \valid_read(a + (0 .. size - 1));
  assigns \nothing;
  ensures size == 0 ==> \result == 1;
  ensures size > 0 ==> 1 <= \result <= size;
  ensures \result >= 1;
*/
int foo200(int * a, int a_len, int size) {

        int max_so_far = 0;
        int max_ending_here = 0;
        int start = 0;
        int end = 0;
        int s = 0;

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= size;
          loop invariant 0 <= s <= i + 1;
          loop invariant 0 <= start <= size;
          loop invariant 0 <= end <= size;
          loop invariant start <= end + 1;
          loop assigns i, max_ending_here, max_so_far, start, end, s;
            */
            for (int i = 0; i < size; i++) {
            max_ending_here += a[i];
            if (max_so_far < max_ending_here) {
                max_so_far = max_ending_here;
                start = s;
                end = i;
            }
            if (max_ending_here < 0) {
                max_ending_here = 0;
                s = i + 1;
            }
        }
            
        return end - start + 1;
}
