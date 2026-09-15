
/*@ 
  logic integer count_divisors(integer n, integer limit) = 
    (limit <= 0) ? 0 : (n % limit == 0 ? 1 : 0) + count_divisors(n, limit - 1);
*/

/*@
  requires number > 0;
  assigns \nothing;
  ensures \result == count_divisors(number, number);
*/
int foo283(int number) {

    int div = 0;

    /*@
      loop invariant number == \at(number, Pre);
      loop invariant div == count_divisors(number, c - 1);
      loop invariant 1 <= c <= number + 1;
      loop assigns c, div;
      loop variant number - c;
    */
    for (int c = 1; c <= number; c++) {
        if (number % c == 0) {
            div++;
        }
    }

    return div;
}
