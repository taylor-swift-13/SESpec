
void foo236() {
    unsigned int x;

    x = 268435440;

    /*@
      loop invariant x == 268435440 - 2*(268435440 - x)/2;
      loop invariant x % 2 == 0;
      loop assigns x;
    */
    while (x > 0) {
        x -= 2;
    }

    /*@ assert x % 2 == 0; */
}
