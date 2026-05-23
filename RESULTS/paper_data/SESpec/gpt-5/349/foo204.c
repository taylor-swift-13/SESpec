
/*@ 
  logic integer odd_divisor_sum_up_to(integer n, integer i) =
    i <= 0 ? 0 :
    odd_divisor_sum_up_to(n, i - 1) + ((i <= n && n % i == 0 && i % 2 != 0) ? i : 0);
*/

/*@
  requires n >= 0;
  assigns \nothing;
  ensures \result == odd_divisor_sum_up_to(n, n);
*/
int foo204(int n) {

        int sum = 0;
        
        /*@
          loop invariant 1 <= i <= n + 1;
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
