
/*@
  logic integer odd_divisor_prefix_sum(integer n, integer k) =
    k <= 0 ? 0 :
    (odd_divisor_prefix_sum(n, k - 1) + ((n % k == 0 && k % 2 != 0) ? k : 0));
*/

int foo349(int n) {

        int sum = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant n == \at(n,Pre);
          loop assigns i, sum;
            */
            for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                if (i % 2 != 0) {
                    sum += i;
                }
            }
        }
            
        return sum;
}
