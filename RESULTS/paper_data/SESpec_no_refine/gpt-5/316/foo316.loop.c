
/*@
  logic integer floor_div(integer a, integer b) = b != 0 ? a / b : 0;

  logic integer count_divisors_up_to(integer n, integer t) =
    (t < 2) ? 0 :
    (t == 2 ? ((2 <= t && 2 <= n / 2 && n % 2 == 0) ? 1 : 0)
            : count_divisors_up_to(n, t - 1) + ((t <= n / t && n % t == 0) ? 1 : 0));
*/

/*@
  requires \true;
  ensures \result >= 0;
*/
int foo316(int number) {

    int result = 0;
    if (number == 1)
        return 1;

    /*@
      loop invariant result >= 0;
      loop assigns c, result;
    */
    for (int c = 2; c <= number / c; c++) {
        if (number % c == 0) {
            result++;
            if (number / c == c) {
                break;
            }
        }
    }

    return result;
}
