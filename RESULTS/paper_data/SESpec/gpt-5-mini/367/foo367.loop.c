
/*@ predicate no_small_divisor_up_to(integer n, integer k) =
      \forall integer d; 2 <= d < k ==> n % d != 0;
*/


int foo367(int n) {

        int i = 2;
        
        /*@
          loop invariant (2 <= \at(n,Pre) / 2) ==> no_small_divisor_up_to(\at(n,Pre), i);
          loop invariant (2 <= \at(n,Pre) / 2) ==> (2 <= i && i <= \at(n,Pre) / 2 + 1);
          loop invariant (!(2 <= \at(n,Pre) / 2)) ==> ((i == 2)&&(n == \at(n,Pre)));
          loop invariant n == \at(n,Pre);
          loop assigns i;
        */
        while (i <= n / i) {
            if (n % i == 0) {
                return i;
            }
            i++;
        }
            
        return n;
}
