
/*@
  logic integer partial_div_sum(integer n, integer k) =
    (k <= 1 ? 0
            : partial_div_sum(n, k - 1)
              + (((k - 1) >= 1 && n % (k - 1) == 0) ? (k - 1) : 0));
*/

int foo289(int number) {

        int sum = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i;
          loop invariant sum == partial_div_sum(number, i);
          loop invariant number == \at(number,Pre);
          loop assigns i, sum;
            */
            for (int i = 1; i <= number / 2; i++) {
            if (number % i == 0) {
                sum += i;
            }
        }
            
        return sum;
}
