
void foo210() {
    int x;
    int y;
    int z;

    x = 0;
    y = 0;
    z = 0;

    /*@
      loop invariant y == 2*x;
      loop invariant z == 3*x;
      loop invariant y >= 0;
      loop assigns x, y, z;
    */
    while(unknown()) {
       x = x + 1;
       y = y + 2;
       z = z + 3;
    }

    /*@ assert y >= 0; */
}
