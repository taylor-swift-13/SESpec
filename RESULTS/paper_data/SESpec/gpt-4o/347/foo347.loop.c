
/*@
  logic integer divisor_count(integer x, integer y) =
    \sum(1, y, \lambda integer i; (x % i == 0 ? 1 : 0));
*/

int foo347(int x, int y) {

    if (y < 0) {
        y = -y;
    }
    int count = 0;

    /*@
      loop invariant 1 <= i <= y + 1;
      loop invariant y >= 0;
      loop invariant x == \at(x, Pre);
      loop assigns i, count;
    */
    for (int i = 1; i <= y; i++) {
        if (x % i == 0) {
            count = count + 1;
        }
    }

    return count;
}
