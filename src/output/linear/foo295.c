
void foo295() {
    unsigned int x;
    x = 0;

    /*@
      loop invariant 0 <= x <= 100000000;
      loop invariant x <= 10000000 || (x - 10000000) % 2 == 0;
      loop invariant x >= 10000000 ==> (100000000 - x) % 2 == 0;
      loop assigns x;
    */
    while (x < 100000000) {
        if (x < 10000000) {
            x++;
        } else {
            x += 2;
        }
    }

    /*@ assert x == 100000000; */
}
