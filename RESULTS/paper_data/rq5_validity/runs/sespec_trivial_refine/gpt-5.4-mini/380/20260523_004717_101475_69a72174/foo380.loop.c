
/*@
predicate divisible(integer n, integer k) = k != 0 && n % k == 0;
*/

int foo380(int number) {

        int sum = 0;
        
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i;
          loop invariant i <= number / 2 + 1;
          loop invariant sum == \sum(integer k = 1, i - 1, (divisible(number, k) ? k : 0));
          loop assigns sum, i;
            */
            for (int i = 1; i <= number / 2; i++) {
            if (number % i == 0) {
                sum += i;
            }
        }
            
        return sum;
}
