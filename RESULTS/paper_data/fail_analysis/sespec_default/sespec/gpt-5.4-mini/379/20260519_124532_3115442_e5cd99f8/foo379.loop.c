
/*@
  logic integer sum_even_upto(integer l, integer r) =
    l > r ? 0 :
    (l % 2 == 0 ? l : 0) + sum_even_upto(l + 1, r);
*/

int foo379(int l, int r) {

        int sum = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant l == \at(l,Pre);
          loop invariant r == \at(r,Pre);
          loop assigns i, sum;
            */
            for (int i = l; i <= r; i++) {
            if (i % 2 == 0) {
                sum += i;
            }
        }
            
        return sum;
}
