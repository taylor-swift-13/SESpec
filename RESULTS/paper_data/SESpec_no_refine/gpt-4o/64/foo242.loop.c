
/*@
  logic integer parity(integer x) = x % 2;
*/

void foo242() {

    int i;
    int j;
    int a;
    int b;

    a = 0;
    b = 0;
    j = 1;
    i = 1;

    /*@
      loop invariant i >= 1;
      loop invariant j >= 1;
      loop invariant a == i / 2;
      loop invariant parity(i) == 1; // i starts at 1 and increments by 2, so it remains odd
      loop assigns a, b, i, j;
    */
    while (unknown()) {
        a = a + 1;
        b = b + j - i;
        i = i + 2;
        if (i % 2 == 0) {
            j = j + 2;
        } else {
            j = j + 1;
        }
    }
}
