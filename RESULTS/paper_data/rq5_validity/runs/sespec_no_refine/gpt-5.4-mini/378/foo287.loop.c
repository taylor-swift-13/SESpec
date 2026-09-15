
/*@
  logic integer sum_odd_upto(integer l, integer r) =
    l > r ? 0 :
    (l % 2 != 0 ? l : 0) + sum_odd_upto(l + 1, r);
*/

int foo287(int l, int r) {

        int sum = 0;
        
            
        /*@
          loop invariant r == \at(r,Pre);
          loop invariant l == \at(l,Pre);
          loop assigns i, sum;
            */
            for (int i = l; i <= r; i++) {
            if (i % 2 != 0) {
                sum += i;
            }
        }
            
        return sum;
}
