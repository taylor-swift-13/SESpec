
/*@ logic integer is_odd_divisor(integer n, integer i) =
      ((1 <= i) && (i <= n) && (n % i == 0) && (i % 2 != 0)) ? 1 : 0; */

/*@ logic integer odd_divisor_sum_up_to(integer n, integer k) =
      (k <= 0) ? 0
               : odd_divisor_sum_up_to(n, k - 1)
                 + ((1 <= k && k <= n && n % k == 0 && k % 2 != 0) ? k : 0); */

int foo204(int n) {

        int sum = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant i >= 1;
          loop invariant sum == odd_divisor_sum_up_to(n, i - 1);
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
