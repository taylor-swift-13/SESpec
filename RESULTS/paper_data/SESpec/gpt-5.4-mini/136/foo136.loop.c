
/*@
  logic integer sq(integer v) = v * v;
*/
        
int foo136(int x) {

        int l = 0, r = x, ans = -1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 <= \at(x,Pre)) ==> (0 <= l <= \at(x,Pre) + 1);
          loop invariant (0 <= \at(x,Pre)) ==> (-1 <= ans < l);
          loop invariant (0 <= \at(x,Pre)) ==> (r <= \at(x,Pre));
          loop invariant (0 <= \at(x,Pre)) ==> (ans == -1 || sq(ans) <= x);
          loop invariant (0 <= \at(x,Pre)) ==> (ans == -1 || sq(ans) <= \at(x,Pre));
          loop invariant (0 <= \at(x,Pre)) ==> (((ans == -1)&&(r == \at(x,Pre))&&(l == 0)&&(x == \at(x,Pre))) || (l > 0));
          loop invariant (0 <= \at(x,Pre)) ==> (((ans == -1)&&(r == \at(x,Pre))&&(l == 0)&&(x == \at(x,Pre))) || (r < \at(x,Pre)));
          loop invariant (0 <= \at(x,Pre)) ==> (((ans == -1)&&(r == \at(x,Pre))&&(l == 0)&&(x == \at(x,Pre))) || (ans >= 0));
          loop invariant (!(0 <= \at(x,Pre))) ==> ((ans == -1)&&(r == \at(x,Pre))&&(l == 0)&&(x == \at(x,Pre)));
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
