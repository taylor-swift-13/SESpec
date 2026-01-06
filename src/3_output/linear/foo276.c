
void foo276() {
    int i;
    int j;

    i = 0;
    j = 0;

    /*@
      loop invariant i >= 0 && i <= 100;
      loop invariant j == 2 * i;
      loop assigns i, j;
    */
    while (i < 100) {
       j += 2;
       i++;
    }

    /*@ assert j == 200; */
}
