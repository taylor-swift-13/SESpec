
/*@
  logic integer sum_cubes(integer n) =
    n <= 0 ? 0 : sum_cubes(n - 1) + n * n * n;
*/

/*@
  logic integer sum_n(integer n) =
    n <= 0 ? 0 : sum_n(n - 1) + n;
*/

int foo172(int n) {

        int sum = 0;
        int sum1 = 0;
        
            
        /*@
          loop invariant sum1 == 0;
          loop invariant n == \at(n,Pre);
          loop assigns i, sum;
        */
            for (int i = 1; i <= n; i++) {
            sum += i * i * i;
        }
            
        /*@
          loop invariant n == \at(n,Pre);
          loop assigns i, sum1;
        */
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i <= n + 1;
          loop invariant sum1 == sum_n(i - 1);
          loop invariant n == \at(n,Pre);
          loop assigns i, sum1;
            */
            for (int i = 1; i <= n; i++) {
            sum1 += i;
        }
            
        return sum - sum1;
}
