/*@ 
  assigns \nothing;

  behavior nonpos:
    assumes y <= 0;
    ensures y == \old(y);

  behavior pos:
    assumes y > 0;
    ensures y == 0;

  complete behaviors;
  disjoint behaviors;
*/
void foo284(int y) {

    int x;

    x = 4 * y;

    /*@
      loop invariant x == 4 * y;
      loop invariant y <= \at(y, Pre);
      loop assigns x, y;
      loop variant y;
    */
    while (x > 0) {
       x -= 4;
       y--;
      }

  }
