
/*@
  // Helper logic: number of divisors of n in the half-range [2 .. t],
  // i.e., count of k such that 2 <= k <= t and k divides n.
  logic integer half_divisors_count(integer n, integer t) =
    (t < 2) ? 0 :
    (t % 2 == 0 ? (n % t == 0 ? 1 : 0) : (n % t == 0 ? 1 : 0))
    + half_divisors_count(n, t - 1);
*/

int foo323(int n) {

        int count = 0;
        if (n == 1) return 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 2 <= i;
          loop invariant count >= 0;
          loop invariant count == half_divisors_count(n, i - 1);
          loop assigns i, count;
            */
            for (int i = 2; i <= n / i; i++) {
            if (n % i == 0) {
                count++;
                if (n / i == i) {
                    break;
                }
            }
        }
            
        return count;
}
