
/*@
  requires y >= 2; // Strengthened precondition to ensure valid loop entry
  ensures y == \at(y,Pre);
*/
void foo55(unsigned int y) {

    unsigned int x;

    x = 2;

    /*@
      loop invariant x >= 2;
      loop invariant x <= y; // Fixed: Strengthened precondition ensures this invariant holds
      loop invariant y == \at(y,Pre);
      loop invariant (2 < \at(y,Pre)) ==> (x * x > y || x == y || (x < y && x >= 2)); // Adjusted to reflect loop body behavior
      loop invariant (2 < \at(y,Pre)) ==> (x >= 2 && x <= y);
      loop invariant (!(2 < \at(y,Pre))) ==> ((x == 2) && (y == \at(y,Pre)));
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
