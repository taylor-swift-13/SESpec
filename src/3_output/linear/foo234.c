
void foo234() {
    unsigned int x;

    x = 0;

    /*@
      loop invariant x % 2 == 0;
      loop assigns x;
    */
    while (x < N) {
        x += 2;
    }

    /*@ assert x % 2 == 0; */
}
