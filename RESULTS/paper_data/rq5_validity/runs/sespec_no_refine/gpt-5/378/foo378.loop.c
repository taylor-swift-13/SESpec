
/*@
  logic integer odd_sum(integer a, integer b) =
    (b < a) ? 0 :
    ((a % 2 != 0) ? a : 0) + odd_sum(a + 1, b);
*/

int foo378(int l, int r) {

        int sum = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
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
