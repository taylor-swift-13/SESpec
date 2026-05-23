
/*@
  logic integer div_floor(integer a, integer b) = (a / b);
*/

/*@
  logic integer mod(integer a, integer b) = (a % b);
*/

/*@
  predicate is_divisor(integer n, integer i) = (mod(n, i) == 0);
*/

/*@
  requires n > 0;
  assigns \nothing;
  ensures n == 1 ==> \result == 1;
  ensures n > 1 ==> \result >= 0;
  ensures n > 1 ==> \result == 
    (\sum integer i; 2 <= i <= div_floor(n, i) && is_divisor(n, i) ? 1 : 0);
*/
int foo141(int n) {

    int count = 0;
    if (n == 1) return 1;

    /*@
      loop invariant 2 <= i <= n / i + 1;
      loop invariant count == (\sum integer j; 2 <= j < i && is_divisor(n, j) ? 1 : 0);
      loop assigns i, count;
      loop variant n / i - i;
    */
    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            count++;
            if (n / i == i) {
                break;
            }
        }
    }

    return count;
}
