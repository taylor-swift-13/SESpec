
/*@
  logic integer divcnt(integer n, integer lo, integer hi) =
    lo > hi ? 0
            : (lo == hi
               ? ((n % lo == 0) ? 1 : 0)
               : divcnt(n, lo, hi - 1) + ((n % hi == 0) ? 1 : 0));
*/

const char * foo285(int n) {

        int count = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant n == \at(n,Pre);
          loop invariant (i == 1) || (1 <= i <= n + 1);
          loop invariant 0 <= count <= (i - 1);
          loop invariant count == divcnt(\at(n,Pre), 1, i - 1);
          loop invariant (i <= n) ==> (count + ((n % i == 0) ? 1 : 0) == divcnt(\at(n,Pre), 1, i));
          loop invariant (i == n + 1) ==> (count == divcnt(\at(n,Pre), 1, n));
          loop assigns i, count;
            */
            for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                count++;
            }
        }
            
        if (count % 2 == 0) {
            return "Even";
        } else {
            return "Odd";
        }
}
