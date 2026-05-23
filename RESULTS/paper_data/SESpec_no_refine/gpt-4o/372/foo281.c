
/*@
  logic integer count_divisors(integer n, integer limit) =
    (limit <= 0) ? 0 : (n % limit == 0 ? 1 : 0) + count_divisors(n, limit - 1);
*/

/*@
  requires num >= 0;
  assigns \nothing;
  ensures \result == count_divisors(num, num);
*/
int foo281(int num) {
    int div = 0;

    /*@
      loop invariant 1 <= c <= num + 1;
      loop invariant div == count_divisors(num, c - 1);
      loop invariant num == \at(num, Pre);
      loop assigns c, div;
      loop variant num - c;
    */
    for (int c = 1; c <= num; c++) {
        if (num % c == 0) {
            div++;
        }
    }

    return div;
}
