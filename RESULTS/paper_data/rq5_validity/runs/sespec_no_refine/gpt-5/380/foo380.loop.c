
/*@
  logic integer divsum_prefix(integer n, integer k) =
    (k <= 0) ? 0 :
    divsum_prefix(n, k - 1) + ((n % k == 0) ? k : 0);
*/

int foo380(int number) {

        int sum = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
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
