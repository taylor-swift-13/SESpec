#include <limits.h>

int mySqrt(int x);

/*@ 
  @ assigns \nothing;
  @ behavior negative:
  @   assumes x < 0;
  @   ensures \result == -1;
  @ behavior nonneg:
  @   assumes x >= 0;
  @   ensures \result >= 0;
  @   ensures (\integer(\result) * \result) <= \integer(x);
  @   ensures \integer(x) < \integer(\result + 1) * (\result + 1);
  @ complete behaviors;
  @ disjoint behaviors;
  @*/
int mySqrt(int x) {

        int l = 0, r = x, ans = -1;
        /*@
          loop invariant 0 <= l;
          loop invariant r <= x;
          loop invariant -1 <= ans < l;
          loop invariant \forall integer y; 0 <= y < l ==> y*y <= \integer(x);
          loop invariant \forall integer y; r < y && y <= x ==> y*y > \integer(x);
          loop assigns l, r, ans;
          loop variant (r >= l ? r - l + 1 : 0);
        */
        while (l <= r) {
            int mid = l + (r - l) / 2;
            /*@ assert l <= mid <= r; */
            if ((long) mid * mid <= x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
}
