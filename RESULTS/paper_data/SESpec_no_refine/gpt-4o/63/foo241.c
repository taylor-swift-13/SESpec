
/*@
  logic integer parity(integer x) = x % 2;
*/

void foo241() {

    int i;
    int j;
    int a;
    int b;

    a = 0;
    b = 0;
    j = 1;
    i = 0;

    /*@
      loop invariant i >= 0;
      loop invariant j >= 1;
      loop invariant a == i / 2;
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
