
/*@
  logic integer sum_slice(int* a, integer lo, integer hi) =
    lo >= hi ? 0 : sum_slice(a, lo, hi - 1) + a[hi - 1];
*/

/*@
  requires \valid(a + (0..a_len-1));
  requires 0 <= size <= a_len;
  assigns \nothing;
  ensures \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k],Pre);
  ensures a_len == \at(a_len,Pre) && size == \at(size,Pre) && a == \at(a,Pre);
*/
int foo200(int * a, int a_len, int size) {

        int max_so_far = 0;
        int max_ending_here = 0;
        int start = 0;
        int end = 0;
        int s = 0;

        /*@
          loop invariant 0 <= i <= size;
          loop invariant 0 <= max_so_far;
          loop invariant 0 <= max_ending_here;
          loop invariant 0 <= start <= a_len;
          loop invariant 0 <= end <= a_len;
          loop invariant 0 <= s <= a_len;

          loop invariant max_so_far >= 0 && max_ending_here >= 0;
          loop invariant (max_ending_here > max_so_far) ==> (start == s && end == i - 1 && max_so_far == max_ending_here);

          loop invariant size == \at(size,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k],Pre);

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
