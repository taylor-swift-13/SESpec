
/*@
  logic integer count_divisors(integer num, integer c) =
    c <= 1 ? 0 : (num % c == 0 ? 1 : 0) + count_divisors(num, c - 1);
*/

/*@
  requires num > 0;
  assigns \nothing;
  ensures num == 1 ==> \result == 1;
  ensures \result >= 0;
*/
int foo318(int num) {
    int result = 0;
    if (num == 1)
        return 1;

    /*@
      loop invariant result >= 0; // Ensure result is non-negative
      loop invariant \forall integer k; 2 <= k < c ==> (num % k == 0 ==> k <= num / k);
      loop assigns c, result;
      loop variant num / c - c;
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
