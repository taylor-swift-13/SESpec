
/*@
  logic integer oddsum(integer a, integer b) =
    a > b ? 0 : (((a % 2) != 0 ? a : 0) + oddsum(a + 1, b));
*/

        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        
int foo378(int l, int r) {

        int sum = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant l <= i;
          loop invariant (l <= r + 1) ==> (i <= r + 1);
          loop invariant !(l <= r + 1) ==> (i == l);
          loop invariant sum + oddsum(i, r) == oddsum(l, r);
          loop assigns i, sum;
            */
            for (int i = l; i <= r; i++) {
            if (i % 2 != 0) {
                sum += i;
            }
        }
            
        return sum;
}
