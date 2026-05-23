
void foo55(unsigned int y) {

    unsigned int x;

    x = 2;

    /*@
      loop invariant (2 < \at(y,Pre)) ==> (x >= 2);
      loop invariant (2 < \at(y,Pre)) ==> (x <= y);
      loop invariant (!(2 < \at(y,Pre))) ==> ((x == 2)&&(y == \at(y,Pre)));
      loop invariant y == \at(y,Pre);
      loop assigns x;
    */
    while (x < y) {
        if (x < y / x) {
            x *= x;
        }
        else {
            x++;
        }
    }
}
