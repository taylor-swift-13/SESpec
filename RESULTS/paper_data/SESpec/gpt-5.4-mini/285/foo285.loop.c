
/*@
  logic integer count_divisors(integer n, integer lo, integer hi) =
    lo >= hi ? 0
             : count_divisors(n, lo, hi - 1) + ((hi - 1) != 0 && n % (hi - 1) == 0 ? 1 : 0);
*/

const char * foo285(int n) {

        int count = 0;
        
            
        /*@
          loop invariant 1 <= i;
          loop invariant 0 <= count;
          loop invariant count <= i - 1;
          loop invariant n == \at(n,Pre);
          loop invariant count == count_divisors(n, 1, i);
          loop invariant \forall integer k; 1 <= k < i && k <= n ==> (n % k == 0 ==> count_divisors(n, 1, k + 1) == count_divisors(n, 1, k) + 1);
          loop invariant \forall integer k; 1 <= k < i && k <= n ==> (n % k != 0 ==> count_divisors(n, 1, k + 1) == count_divisors(n, 1, k));
          loop invariant (i <= \at(n,Pre)) ==> (count >= 0 && count <= \at(n,Pre));
          loop invariant (i <= \at(n,Pre)) ==> (count == count_divisors(n, 1, i));
          loop invariant (i > \at(n,Pre)) ==> (count == count_divisors(n, 1, \at(n,Pre) + 1));
          loop assigns i, count;
            */
            for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                count++;
            }
        }
            
        if (count % 2 == 0) {
            return "Even";
        } else {
            return "Odd";
        }
}
