/*@
    requires y % 2 == 0;
    assigns x;
    ensures x >= 99;
*/
void foo227() {

    int x;
    int y;

    x = 0;

    /*@
        loop invariant 0 <= x;
        loop invariant x % 10 == 0;
        loop invariant x < 99 ==> x <= 98;
        loop assigns x;
        loop variant 100 - x;
    */
    while (x < 99) {
       if (y % 2 == 0)
       x += 10;
       else
       x -= 5;
      }

  }
