
void foo148() {
    int x;
    int y;

    x = 1;
    y = 1;

    /*@
      loop invariant x >= 1 && y >= 1;
      loop invariant y >= x;
      loop assigns x, y;
    */
    while(unknown()) {
       x = x + y;
       y = x + y;
    }
}
