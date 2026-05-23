
/*@
  // No additional predicates or logic functions are required.
*/

int foo60_c136(int x) {

        int l = 0, r = x, ans = -1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant x == \at(x,Pre);
          loop invariant 0 <= l && l <= \at(x,Pre) + 1;
          loop invariant -1 <= ans && ans < l;
          loop invariant -1 <= r && r <= \at(x,Pre);
          loop invariant ans == -1 || ((long)ans * (long)ans <= x);
          loop assigns ans, l, r;
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
