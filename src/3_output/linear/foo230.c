
void foo230() {
    unsigned int x;

    x = 0;

    /*@
      loop invariant 0 <= x;
      loop invariant x <= 65520 || (x >= 65520 && (x - 65520) % 2 == 0);
      loop invariant x < 65520 || x % 2 == 0;
      loop assigns x;
    */
    while (x < 268435455) {
        if (x < 65520) {
            x++;
        }
        else {
            x += 2;
        }
    }

    /*@ assert (x % 2 == 0); */
}
