
/*@ 
  assigns \nothing;
  ensures (0 <= x) ==> (\result <= x);
*/
int foo136(int x) {

    int l = 0, r = x, ans = -1;

    /*@
      loop invariant x == \at(x,Pre);
      loop invariant -1 <= ans;
      loop invariant (0 <= \at(x,Pre)) ==> (0 <= l);
      loop invariant (0 <= \at(x,Pre)) ==> (-1 <= r);
      loop invariant (0 <= \at(x,Pre)) ==> (r <= \at(x,Pre));
      loop invariant (0 <= \at(x,Pre)) ==> (l <= r + 1);
      loop invariant (0 <= \at(x,Pre)) ==> (ans < l);
      loop invariant (0 <= \at(x,Pre)) ==> (ans == -1 || (long)ans * (long)ans <= x);
      loop invariant (0 <= \at(x,Pre)) ==> (l == 0 || (long)(l - 1) * (long)(l - 1) <= x);
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
