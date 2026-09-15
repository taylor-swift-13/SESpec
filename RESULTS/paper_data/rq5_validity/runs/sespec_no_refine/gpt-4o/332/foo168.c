
/*@
  predicate PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION = \true;
*/

void foo168() {

    int x;
    int y;
    int z;
    int w;

    x = 0;
    y = 0;
    z = 0;
    w = 0;

    /*@
      loop invariant 0 <= x; // x is non-negative and incremented in all branches
      loop invariant z == 10 * w; // z is always 10 times w
      loop invariant w >= 0; // w is non-negative and incremented in every iteration
      loop assigns x, y, w, z;
    */
    while (unknown()) {
        if (x >= 4) {
            x = x + 1;
            y = y + 2;
        } else if (y > 10 * w && z >= 100 * x) {
            y = 0 - y;
        } else {
            x = x + 1;
            y = y + 100;
        }
        w = w + 1;
        z = z + 10;
    }
}
