
/*@ 
  logic integer even_sum_range(integer a, integer b) =
    a > b ? 0 : ((a % 2 == 0) ? a : 0) + even_sum_range(a + 1, b);
*/

/*@
  assigns \nothing;
*/
int foo379(int l, int r) {

        int sum = 0;
        
        /*@
          loop invariant \at(r,Pre) == r;
          loop invariant \at(l,Pre) == l;
          loop assigns i, sum;
        */
        for (int i = l; i <= r; i++) {
            if (i % 2 == 0) {
                sum += i;
            }
        }
            
        return sum;
}
