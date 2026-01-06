
void foo235() {
    unsigned int x;

    x = 268435441;

    /*@
      loop invariant x % 2 == 1;
      loop invariant x <= 268435441;
      loop assigns x;
    */
    while (x > 1) {
        x -= 2;
    }

    /*@ assert x % 2 == 1; */
}
