
/*@
  logic integer sum(int* a, integer lo, integer hi) =
    hi <= lo ? 0 : sum(a, lo, hi - 1) + a[hi - 1];
*/

/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires 0 <= size <= a_len;
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  assigns \nothing;
  ensures a == \at(a,Pre);
  ensures a_len == \at(a_len,Pre);
  ensures size == \at(size,Pre);
    ensures \result == \result;  
*/
int foo200(int * a, int a_len, int size) {

        int max_so_far = 0;
        int max_ending_here = 0;
        int start = 0;
        int end = 0;
        int s = 0;

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant size == \at(size,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant \forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre);
          loop invariant 0 <= s <= i + 1;
          loop invariant max_ending_here >= 0;
          loop invariant (s == i + 1) ==> (max_ending_here == 0);
          loop invariant max_so_far >= 0;
          loop invariant max_so_far >= max_ending_here;
          loop invariant (i < \at(size,Pre)) ==> (((s == 0)&&(end == 0)&&(start == 0)&&(max_ending_here == 0)&&(max_so_far == 0)&&(size == \at(size,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (max_so_far >= 0 && max_so_far >= max_ending_here));
          loop invariant (i < \at(size,Pre)) ==> (((s == 0)&&(end == 0)&&(start == 0)&&(max_ending_here == 0)&&(max_so_far == 0)&&(size == \at(size,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= start && start <= i));
          loop invariant (i < \at(size,Pre)) ==> (((s == 0)&&(end == 0)&&(start == 0)&&(max_ending_here == 0)&&(max_so_far == 0)&&(size == \at(size,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= s && s <= i + 1));
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
