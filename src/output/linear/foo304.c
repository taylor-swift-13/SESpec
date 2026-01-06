
void foo304() {
    unsigned int x;
    unsigned int z;

    x = 0;
    z = 0;

    /*@
      loop invariant x <= 10000000;
      loop invariant z == 2 * (x >= 5000000 ? x - 5000000 : 0);
      loop invariant z % 2 == 0;
      loop assigns x, z;
    */
    while (x < 10000000) {
        if (x >= 5000000) {
            z = z + 2;
        }
        x++;
    }

    /*@ assert z % 2 == 0; */
}
