/*@
    requires \true;
    assigns \nothing;
    ensures \true;
*/
void foo284(int y) {

    int x;

    x = 4 * y;

    /*@
        loop invariant x == 4 * y;
        loop assigns x, y;
        loop variant (x > 0 ? x : 0);
    */
    while (x > 0) {
       x -= 4;
       y--;
      }

  }
