/*@
  ensures \true;
*/
void foo227() {

    int x;
    int y;

    x = 0;

    /*@
       loop invariant x % 5 == 0;
       loop assigns x;
    */
    while (x < 99) {
       if (y % 2 == 0)
       x += 10;
       else
       x -= 5;
      }

    /*@ assert x == 100; */
    /*@ assert x % 5 == 0; */

  }
