
/*@
logic integer even_sum(integer l, integer r) =
  (l >= r ? 0 : even_sum(l, r - 1) + ((r - 1) % 2 == 0 ? (r - 1) : 0));
*/

int foo379(int l, int r) {

        int sum = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant l <= i;
          loop invariant sum == even_sum(l, i);
          loop assigns i, sum;
            */
            for (int i = l; i <= r; i++) {
            if (i % 2 == 0) {
                sum += i;
            }
        }
            
        return sum;
}
