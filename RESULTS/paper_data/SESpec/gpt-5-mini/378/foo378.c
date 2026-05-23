
/*@ 
  logic integer odd_sum(integer a, integer b) =
    a >= b ? 0 : (a % 2 != 0 ? a + odd_sum(a+1,b) : odd_sum(a+1,b));
*/

/*@
  requires \true;
  assigns \nothing;
*/
int foo378(int l, int r) {

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
