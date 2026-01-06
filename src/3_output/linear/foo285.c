
void foo285() {
    int x;
    int y;
    int z;

    x = 0;
    y = 0;
    z = 0;

    /*@
      loop invariant x == y;
      loop invariant x + y + z == 0;
      loop invariant z == -2 * x;
      loop assigns x, y, z;
    */
    while (x > 0) {
       x++;
       y++;
       z -= 2;
    }

    /*@ assert x + y + z == 0; */
}
