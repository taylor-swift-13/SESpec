
void foo55(unsigned int y) {

    unsigned int x;

    x = 2;

    /*@
      loop invariant x >= 2;
      loop invariant y == \at(y,Pre);
      loop invariant (x >= 2 && y >= 2) ==> (x <= y || x > y);
      loop invariant (x < y) ==> (x >= 2 && y >= 2);
      loop invariant (x < y && x < y / x) ==> (x * x <= y);
      loop invariant (x >= y) ==> (x >= 2 && y == \at(y,Pre));
      loop invariant (2 < \at(y,Pre)) ==> (x >= 2);
      loop invariant (!(2 < \at(y,Pre))) ==> ((x == 2)&&(y == \at(y,Pre)));
      loop assigns x;
    */
    while (x < y) {
      if (x < y / x) {
        x *= x;
      } else {
        x++;
      }
    }

}
