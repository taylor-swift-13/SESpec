/*@
    assigns \nothing;
*/
void foo284(int y) {

    int x;

    x = 4 * y;

    /*@
        loop invariant x == 4 * y;
        loop invariant x >= 0 || y <= 0;
        loop assigns x, y;
        loop variant x;
    */
    while (x > 0) {
       x -= 4;
       y--;
      }

  }
