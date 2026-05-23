
/*@
  logic integer integer_division(integer a, integer b) = (b != 0) ? a / b : 0;
*/

/*@
  logic integer integer_modulo(integer a, integer b) = (b != 0) ? a % b : 0;
*/

/*@
  logic integer count_divisors(integer num, integer limit) =
    (limit <= 1) ? 0 :
    (num % limit == 0) ? 1 + count_divisors(num, limit - 1) :
                         count_divisors(num, limit - 1);
*/

/*@
  requires num >= 1;
  assigns \nothing;
  ensures \result >= 0;
*/
int foo134(int num) {

    int result = 0;
    if (num == 1)
        return 1;

    /*@
      loop invariant result >= 0;
      loop invariant \forall integer k; 2 <= k < c ==> (num % k == 0 ==> \exists integer x; x == k && x <= num / x);
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
