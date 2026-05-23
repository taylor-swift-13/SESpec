
/*@
  logic integer count_divisors(int x, int y) = 
    (y <= 0) ? 0 : (\sum integer i; 1 <= i <= y && x % i == 0; 1);
*/

/*@
  requires \at(y,Pre) >= 0 && (count == 0) * (y == \at(y,Pre)) * (x == \at(x,Pre)) || \at(y,Pre) < 0 && (count == 0) * (y == -\at(y,Pre)) * (x == \at(x,Pre));
*/
int foo199(int x, int y) {

    if (y < 0) {
        y = -y;
    }
    int count = 0;

    /*@
      loop invariant 1 <= i <= y + 1;
      loop invariant count == count_divisors(x, i - 1);
      loop invariant y == \at(y,Pre);
      loop invariant x == \at(x,Pre);
      loop assigns i, count;
    */
    for (int i = 1; i <= y; i++) {
        if (x % i == 0) {
            count = count + 1;
        }
    }

    return count;
}
