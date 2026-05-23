
/*@
  logic integer abs_val(int v) = v < 0 ? -v : v;

  logic integer best_index(int* a, integer lo, integer hi) =
    lo >= hi ? -1
             : ( best_index(a, lo, hi-1) == -1
                 ? (hi-1)
                 : ( ( abs_val(a[hi-1]) < abs_val(a[best_index(a, lo, hi-1)]) )
                     || ( abs_val(a[hi-1]) == abs_val(a[best_index(a, lo, hi-1)]) && a[hi-1] > a[best_index(a, lo, hi-1)]) )
                   ? (hi-1)
                   : best_index(a, lo, hi-1)
               );
*/

/*@
  requires \valid_read(nums + (0 .. nums_len-1));
  requires nums_len >= 0;
*/
int foo106(int * nums, int nums_len) {

        int ans = INT_MAX;

        /* >>> LOOP INVARIANT TO FILL <<< */

        /*@
          loop invariant 0 <= i <= nums_len;
          loop invariant (i == 0) ==> (ans == INT_MAX);
          loop invariant (i > 0) ==> (ans == nums[best_index(nums, 0, i)]);
          loop invariant \forall integer k; 0 <= k < nums_len ==> nums[k] == \at(nums[k], Pre);
          loop assigns i, ans;
        */
        for(int i = 0; i < nums_len; i++) {
            int num = nums[i];
            int absNum = (num<0?-num:num);
            int absAns = (ans<0?-ans:ans);
            if(absNum < absAns || (absNum == absAns && num > ans)) {
                ans = num;
            }
        }

        return ans;
}
