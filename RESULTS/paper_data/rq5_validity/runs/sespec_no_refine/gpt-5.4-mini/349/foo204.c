
/*@ 
  assigns \nothing;
  ensures \result == sum_of_divisors_upto(\old(n), \old(n));
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
