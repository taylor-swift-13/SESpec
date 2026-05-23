
/*@
  logic integer odd_sum(integer l0, integer i, integer r0) =
    i < l0 ? 0
    : i > r0 ? odd_sum(l0, r0, r0)
    : (odd_sum(l0, i-1, r0) + ((i % 2 != 0) ? i : 0));
*/

int foo287_c378(int l, int r) {

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
