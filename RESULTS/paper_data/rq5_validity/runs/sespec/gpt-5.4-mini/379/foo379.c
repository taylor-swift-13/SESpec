
/*@
  logic integer even_sum(integer a, integer b) =
    a > b ? 0 :
    (a % 2 == 0 ? a : 0) + even_sum(a + 1, b);
*/

/*@
  requires l <= r + 1;
  assigns \nothing;
*/
int foo379(int l, int r) {

        int sum = 0;
        
            
        /*@
          loop invariant l <= i <= r + 1;
          loop invariant \true;
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
