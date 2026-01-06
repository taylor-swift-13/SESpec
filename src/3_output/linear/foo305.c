
void foo305() {
    int x;
    x = 0;

    /*@
      loop invariant 0 <= x <= 1000000;
      loop invariant x < 750000 ==> x % 1 == 0;
      loop invariant x >= 750000 ==> x % 2 == 750000 % 2;
      loop assigns x;
    */
    while (x < 1000000) {
        if (x < 750000) {
            x++;
        }
        else {
            x = x + 2;
        }
    }

    /*@ assert x == 1000000; */
}
