
/*@ logic integer divisors_sum(integer n, integer k) =
      k <= 0 ? 0 : divisors_sum(n, k - 1) + ((n % k == 0) ? k : 0);
*/

/*@
  requires number >= 0;
  assigns \nothing;
  ensures \result >= 0;
  ensures number < 2 ==> \result == 0;
*/
int foo380(int number) {
    int sum = 0;
    int i = 1;

    /*@
      loop invariant 1 <= i;
      loop invariant i <= number / 2 + 1;
      loop invariant sum >= 0;
      loop invariant sum == divisors_sum(number, i - 1);
      loop assigns sum, i;
      loop variant number / 2 + 1 - i;
    */
    while (i <= number / 2) {
        if (number % i == 0) {
            sum += i;
        }
        i++;
    }

    return sum;
}
