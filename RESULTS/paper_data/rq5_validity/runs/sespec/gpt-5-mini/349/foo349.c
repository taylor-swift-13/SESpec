
/*@
  logic integer odd_divisor_sum_prefix(integer m, integer k) =
    k <= 0 ? 0
    : ((m % k == 0 && k % 2 != 0) ? k : 0) + odd_divisor_sum_prefix(m, k-1);
*/
/*@
  logic integer odd_divisor_sum(integer m) = odd_divisor_sum_prefix(m, m);
*/

/*@
  requires n >= 0;
  ensures \result == odd_divisor_sum(\at(n,Pre));
  ensures \result >= 0;
  ensures (\at(n,Pre) == 0) ==> \result == 0;
  assigns \nothing;
*/
int foo349(int n) {

    int sum = 0;

    /*@
      loop invariant 1 <= i && i <= n + 1;
      loop invariant 0 <= sum;
      loop invariant n == \at(n,Pre);

      loop invariant sum == odd_divisor_sum_prefix(\at(n,Pre), i-1);

      loop invariant \forall integer k;
        1 <= k <= i-1 ==>
          ((\at(n,Pre) % k == 0 && k % 2 != 0) ==> 1 <= k && k <= i-1);

      loop invariant (!(i <= \at(n,Pre))) ==> (sum == odd_divisor_sum(\at(n,Pre)));

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
