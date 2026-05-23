
/*@
  /* No extra predicates needed for these simple numeric invariants. */
*/

int foo136(int x) {

        int l = 0, r = x, ans = -1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 <= \at(x,Pre)) ==> 0 <= l && l <= r + 1 && r <= \at(x,Pre);
          loop invariant (0 <= \at(x,Pre)) ==> (ans == -1 || (0 <= ans && ans * ans <= \at(x,Pre)));
          loop invariant (0 <= \at(x,Pre)) ==> (ans == -1 || ans <= r);
          loop invariant (!(0 <= \at(x,Pre))) ==> ((ans == -1) && (r == \at(x,Pre)) && (l == 0) && (x == \at(x,Pre)));
          loop invariant x == \at(x,Pre);
          loop assigns mid, ans, l, r;
            */
            while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((long) mid * mid <= x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
            
        return ans;
}
