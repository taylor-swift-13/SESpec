
/*@
  logic integer even_sum_range(integer a, integer b) =
    a > b ? 0 :
    (a % 2 == 0 ? a + even_sum_range(a+1,b) : even_sum_range(a+1,b));
*/


int foo379(int l, int r) {

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
