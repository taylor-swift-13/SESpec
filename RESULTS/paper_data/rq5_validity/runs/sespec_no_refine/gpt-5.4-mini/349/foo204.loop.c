
/*@
  logic integer sum_of_divisors_upto(integer n, integer i) =
    i <= 0 ? 0 :
    sum_of_divisors_upto(n, i - 1) + (((i != 0) && (n % i == 0) && (i % 2 != 0)) ? i : 0);
*/

int foo204(int n) {

        int sum = 0;
        
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
