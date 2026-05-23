
/*@
  predicate is_multiple_of_3(unsigned int x) = (x % 3 == 0);
*/

/*@
  predicate y_invariant(unsigned int x, unsigned int y) =
    ((x % 3 == 1 && y == 0) || (x % 3 == 2 && y == 0) || (x % 3 == 0 && y == 1));
*/

void foo231() {

    unsigned int x;
    unsigned int y;

    y = 1;

    /*@
      loop invariant ((y == 1) && is_multiple_of_3(x)) || y_invariant(x, y);
      loop assigns x, y;
    */
    while(unknown()) {
        if (x % 3 == 1) {
            x = x + 2;
            y = 0;
        } else {
            if (x % 3 == 2) {
                x = x + 1;
                y = 0;
            } else {
                if (unknown()) {
                    x = x + 4;
                    y = 1;
                } else {
                    x = x + 5;
                    y = 1;
                }
            }
        }
    }
}
