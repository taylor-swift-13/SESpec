


void foo51() {

    int x;
    int y;
    int z;
    int w;

    x = 0;
    y = 0;
    z = 0;
    w = 0;

    /* >>> LOOP INVARIANT TO FILL <<< */
    /*@
      loop invariant x == w && z == 10 * w;
      loop invariant x >= 0;
      loop invariant (x < 4) ==> (y == 100 * x);
      loop invariant (x >= 4) ==> (y == 2 * x + 392);
      loop assigns x, y, z, w;
    */
    while (unknown()) {
      if (x >= 4) {
        x = x + 1;
        y = y + 2;
      }
      else if (y > 10 * w && z >= 100 * x) {
        y = 0 - y;
      }
      else {
        x = x + 1;
        y = y + 100;
      }
      w = w + 1;
      z = z + 10;
    }
}
