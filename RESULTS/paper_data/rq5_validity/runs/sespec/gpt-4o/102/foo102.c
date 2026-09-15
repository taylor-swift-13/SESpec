
/*@
  logic integer digit_sum(integer n) =
    n == 0 ? 0 : (n % 10) + digit_sum(n / 10);
*/

/*@
  requires num >= 0;
  assigns \nothing;
  ensures \result >= 0 && \result < 10;
*/
int foo102(int num) {

    /*@
      loop invariant num >= 0;
      loop invariant (\at(num, Pre) < 10) ==> (num == \at(num, Pre));
      loop invariant \exists integer k; num == k && k >= 0;
      loop assigns num;
      loop variant num;
    */
    while (num >= 10) {
        int sum = 0;

        /*@
          loop invariant num >= 0;
          loop invariant sum >= 0;
          loop invariant \exists integer k; num == k && k >= 0;
          loop assigns sum, num;
          loop variant num;
        */
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }

        num = sum;
    }

    return num;
}
