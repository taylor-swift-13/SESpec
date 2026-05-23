
/*@
  logic integer count_divisors(integer num, integer c) =
    c <= 1 ? 0 : (num % c == 0 ? 1 : 0) + count_divisors(num, c - 1);
*/

/*@
  requires num > 0;
  ensures \result == count_divisors(num, num / 2);
*/
int foo318(int num) {
    int result = 0;
    if (num == 1)
        return 1;

    /*@
      loop invariant \forall integer k; 2 <= k < c ==> (num % k == 0 ==> k <= num / k);
      loop assigns c, result;
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
