
/*@
  logic integer initial_x = \at(x, Pre);
  logic integer initial_y = \at(y, Pre);
*/

/*@
  requires x >= 0;
  requires y > 0;
  ensures x == y * \result + r;
  ensures 0 <= r < y;
  assigns \nothing;
*/
int foo398(int x, int y) {
  int q = 0;
  int r = 0;

  /*@
    loop invariant initial_x == initial_y * q + r + y * (q - 1) + r;
    loop invariant 0 <= r < y;
    loop invariant x == initial_y * q + r;
    loop invariant y == initial_y;
    loop invariant x == initial_x;
    loop assigns r, q;
  */
  while (x > y * q + r) {
    if (r == y - 1) {
      r = 0;
      q += 1;
    } else {
      r += 1;
    }
  }

  return q;
}
