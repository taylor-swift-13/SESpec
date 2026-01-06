
void foo208() {
    int x;

    x = 0;

    /*@
      loop invariant 0 <= x <= 6;
      loop assigns x;
    */
    while (x < 6) {
        x = x + 1;
    }

    /*@ assert x == 6; */
}
