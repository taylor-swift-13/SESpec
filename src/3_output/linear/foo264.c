
void foo264() {
    int x;
    int y;

    x = 1;
    y = 1;

    /*@
      loop invariant x == y;
      loop invariant ((y == 1) && (x == 1)) || (x >= 1 && y >= 1);
      loop assigns x, y;
    */
    while (unknown()) {
       x = x + y;
       y = x;
    }

    /*@ assert y >= 1; */
}
