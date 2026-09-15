
/*@
  logic integer gcd_count_upto(integer x, integer y, integer i) =
    \sum(1, i, \lambda integer k; (x % k == 0 && y % k == 0) ? 1 : 0);
*/

int foo290(int x, int y) {

    int count = 0;

    /*@
      loop invariant y == \at(y,Pre);
      loop invariant x == \at(x,Pre);
      loop invariant count >= 0;
      loop assigns i, count;
    */
    for (int i = 1; i <= x && i <= y; i++) {
        if (x % i == 0 && y % i == 0) {
            count++;
        }
    }

    return count;
}
