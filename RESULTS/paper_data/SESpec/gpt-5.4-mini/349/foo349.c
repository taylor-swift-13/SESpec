
/*@ logic integer odd_divisor_sum(integer n, integer i) =
      i < 1 ? 0 :
      odd_divisor_sum(n, i - 1) + (((n % i == 0) && (i % 2 != 0)) ? i : 0);
*/
/*@
  assigns \nothing;
  ensures \result >= 0;
  ensures \at(n,Pre) < 1 ==> \result >= 0;
  ensures \at(n,Pre) > 0 ==> \result >= 0;
  ensures \result >= 0;
*/
int foo349(int n) {

        int sum = 0;
        
        /*@
          loop invariant i >= 1;
          loop invariant sum >= 0;
          loop invariant n == \at(n,Pre);
          loop invariant (i <= \at(n,Pre)) ==> (sum >= 0);
          loop invariant (!(i <= \at(n,Pre))) ==> (sum >= 0);
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
