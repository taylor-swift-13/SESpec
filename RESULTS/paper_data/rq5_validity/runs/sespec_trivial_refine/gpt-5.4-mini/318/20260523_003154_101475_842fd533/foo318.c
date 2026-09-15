
/*@
logic boolean is_divisor(integer n, integer c) = (c != 0) && (n % c == 0);

logic integer count_divisors(integer n, integer c) =
  c > n / c ? 0 :
  (is_divisor(n, c) ? 1 : 0) + count_divisors(n, c + 1);
*/

/*@
  assigns \nothing;
  ensures num == 1 ==> \result == 1;
  ensures num != 1 ==> \result >= 0;
  ensures \result >= 0;
*/
int foo318(int num) {

    int result = 0;
    if (num == 1)
        return 1;

    /*@
      loop invariant 2 <= c;
      loop invariant 0 <= result;
      loop assigns result, c;
    */
    for (int c = 2; c <= num / c; c++) {
        if (num % c == 0) {
            result++;
            if (num / c == c) {
                break;
            }
        }
    }

    return result;
}
