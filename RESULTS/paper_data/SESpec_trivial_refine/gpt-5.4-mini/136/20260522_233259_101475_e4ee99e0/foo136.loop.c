
/*@

*/

int foo136(int x) {

        int l = 0, r = x, ans = -1;
        
        /*@
          loop invariant l >= 0;
          loop invariant r <= x;
          loop invariant l <= r + 1;
          loop invariant ans == -1 || ((long)ans * ans <= x && ans < l);
          loop assigns l, r, ans;
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
