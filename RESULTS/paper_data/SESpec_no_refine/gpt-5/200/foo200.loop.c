
/*@
  logic integer sum(int* a, integer lo, integer hi) =
    lo >= hi ? 0 : sum(a, lo, hi - 1) + a[hi - 1];
*/

int foo200(int * a, int a_len, int size) {

        int max_so_far = 0;
        int max_ending_here = 0;
        int start = 0;
        int end = 0;
        int s = 0;

        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= s <= i;
          loop invariant 0 <= start <= i;
          loop invariant -1 <= end <= i;
          loop invariant max_ending_here >= 0;
          loop invariant max_so_far >= 0;
          loop invariant size == size;
          loop invariant a_len == a_len;
          loop invariant a == a;
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
