/*@
    requires y <= UINT_MAX;
    assigns \nothing;
*/
void foo232(unsigned int y) {

    unsigned int x;
    /*@
        loop invariant 2 <= x;
        loop invariant x <= UINT_MAX;
        loop assigns x;
        loop variant y - x;
    */
    x = 2;

    while (x < y) {
       if (x < y / x) {
       x *= x;
      }
       else {
       x++;
      }
      }

  }
