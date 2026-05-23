
/*@
  logic integer gcd(int a, int b) = 
    (b == 0) ? a : gcd(b, a % b);
*/

/*@
  logic integer count_common_divisors(int x, int y) =
    \sum(1, \min(x, y), (\lambda integer i; (x % i == 0 && y % i == 0) ? 1 : 0));
*/

/*@
  requires x >= 0 && y >= 0;
  ensures \result == count_common_divisors(x, y);
*/
int foo290(int x, int y) {

    int count = 0;

    /*@
      loop invariant 1 <= i <= \min(x, y) + 1;
      loop invariant count == count_common_divisors(x, y) - count_common_divisors(x, y) + \sum(1, i - 1, (\lambda integer k; (x % k == 0 && y % k == 0) ? 1 : 0));
      loop invariant y == \at(y,Pre);
      loop invariant x == \at(x,Pre);
      loop assigns i, count;
    */
    for (int i = 1; i <= x && i <= y; i++) {
        if (x % i == 0 && y % i == 0) {
            count++;
        }
    }

    return count;
}
