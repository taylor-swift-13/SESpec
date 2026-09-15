
/*@
  logic integer max2(integer x, integer y) = x >= y ? x : y;

  logic integer best_end(int* a, integer i) =
    i <= 0 ? 0 : max2(0, best_end(a, i - 1) + a[i - 1]);

  logic integer best_overall(int* a, integer i) =
    i <= 0 ? 0 : max2(best_overall(a, i - 1), best_end(a, i));
*/

/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires size == 0;
  requires size <= a_len;
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  assigns \nothing;
  ensures size > 0 ==> \result <= size;
  ensures a_len == \old(a_len);
  ensures \forall integer k; 0 <= k < a_len ==> a[k] == \old(a[k]);
*/
int foo200(int * a, int a_len, int size) {

        int max_so_far = 0;
        int max_ending_here = 0;
        int start = 0;
        int end = 0;
        int s = 0;

        
            
        /*@
          loop invariant 0 <= i;
          loop invariant 0 <= max_so_far;
          loop invariant 0 <= max_ending_here;
          loop invariant 0 <= start <= i;
          loop invariant 0 <= end <= i;
          loop invariant 0 <= s <= i;
          loop invariant max_ending_here <= max_so_far;
          loop invariant max_ending_here == best_end(a, i);
          loop invariant max_so_far >= best_overall(a, i);
          loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
          loop invariant (i < \at(size,Pre)) ==> (max_so_far >= max_ending_here);
          loop invariant (i < \at(size,Pre)) ==> (max_so_far >= best_overall(a, i));
          loop invariant (i < \at(size,Pre)) ==> (max_ending_here == best_end(a, i));
          loop invariant (i < \at(size,Pre)) ==> (0 <= start <= i);
          loop invariant (i < \at(size,Pre)) ==> (0 <= end <= i);
          loop invariant (i < \at(size,Pre)) ==> (0 <= s <= i);
          loop invariant (!(i < \at(size,Pre))) ==> (i >= \at(size,Pre));
          loop invariant size == \at(size,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
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
