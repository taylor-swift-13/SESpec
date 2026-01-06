
void foo253() {
    int i;
    int j;
    int a;
    int b;

    a = 0;
    b = 0;
    j = 1;
    i = 1;

    /*@
      loop invariant i == 2*a + 1;
      loop invariant j == a + 1;
      loop invariant a >= 0;
      loop invariant b == -(a * (a - 1)) / 2;
      loop assigns a, b, i, j;
    */
    while (unknown()) {
        a = a + 1;
        b = b + j - i;
        i = i + 2;
        if (i % 2 == 0) {
            j = j + 2;
        }
        else {
            j = j + 1;
        }
    }

    /*@ assert (a != 0) ==> (a != b); */
}
