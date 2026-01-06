
void foo224() {
    int x;
    x = 0;

    /*@
      loop invariant x == 0 || x % 4 == 0;
      loop invariant x >= 0;
      loop assigns x;
    */
    while(unknown()) {
        x = x + 4;
    }

    /*@ assert x % 4 == 0; */
}
