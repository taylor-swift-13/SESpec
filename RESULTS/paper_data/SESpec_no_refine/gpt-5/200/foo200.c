
/*@
  logic integer sum(int* a, integer lo, integer hi) =
    lo >= hi ? 0 : sum(a, lo, hi - 1) + a[hi - 1];
*/

/*@
  logic integer last_positive_index(int* a, integer n) =
    n <= 0 ? -1 :
    (a[n-1] > 0 ? (n-1) : last_positive_index(a, n-1));
*/
/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;
  assigns \nothing;
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
