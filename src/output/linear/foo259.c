
void foo259() {
    int x;
    x = 0;

    /*@
      loop invariant ((x == 0) || (1 <= x <= 40));
      loop assigns x;
    */
    while (unknown()) {
        if (unknown()) {
            x = x + 1;
            if (x > 40) {
                x = 0;
            }
        }
    }

    /*@ assert x <= 40; */
}
