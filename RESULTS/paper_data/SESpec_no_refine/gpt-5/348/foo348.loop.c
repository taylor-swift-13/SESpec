
/*@
  logic integer not_divisible_count(integer l, integer u, integer a) =
    (u < l) ? 0 : not_divisible_count(l, u - 1, a) + ((u % a != 0) ? 1 : 0);
*/

int foo348(int a, int n, int l, int r) {

        int count = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant l == \at(l,Pre);
          loop invariant r == \at(r,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant n == \at(n,Pre);
          loop assigns i, count;
            */
            for (int i = l; i <= r; i++) {
            if (i % a != 0) {
                count++;
            }
            if (count == n) {
                return i;
            }
        }
            
        return -1;
}
