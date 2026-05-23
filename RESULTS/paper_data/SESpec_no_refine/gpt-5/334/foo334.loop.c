
/*@
  logic integer tri(integer m) = m <= 0 ? 0 : m * (m + 1) / 2;

  logic integer cube_sum(integer m) =
    m <= 0 ? 0 : m*m*m + cube_sum(m - 1);
*/

        /*@
        */
        
/*@
  requires \true;
*/

int foo334(int n) {

        int sum = 0;
        int sum1 = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant sum1 == 0;
          loop invariant n == \at(n,Pre);
          loop invariant sum1 == 0;
          loop invariant n == \at(n,Pre);
          loop assigns i, sum;
            */
            for (int i = 1; i <= n; i++) {
            sum += i * i * i;
        }
            
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i <= n + 1;
          loop invariant sum1 == tri(i - 1);
          loop invariant sum == cube_sum(n);
          loop invariant n == \at(n,Pre);
          loop assigns i, sum1;
            */
            for (int i = 1; i <= n; i++) {
            sum1 += i;
        }
            
        return sum - sum1;
}
