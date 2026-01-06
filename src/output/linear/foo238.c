
void foo238() {
    unsigned int i;
    unsigned int j;
    unsigned int k;

    i = 0;
    j = 0;
    k = 0;

    /*@
      loop invariant k == 3 * i;
      loop invariant j == 2 * i;
      loop assigns i, j, k;
    */
    while (k < 268435455) {
       i = i + 1;
       j = j + 2;
       k = k + 3;
    }

    /*@ assert k == 3 * i; */
}
