
/*@
  logic integer sum_from(integer l, integer r) =
    l > r ? 0 : l + sum_from(l + 1, r);
*/

int foo288(int l, int r) {

        int sum = 0;
        
            
        /*@
          loop invariant r == \at(r,Pre);
          loop invariant l == \at(l,Pre);
          loop assigns i, sum;
            */
            for (int i = l; i <= r; i++) {
            if (i % 2 == 0) {
                sum += i;
            }
        }
            
        return sum;
}
