int unknown();

/*@
    assigns a, b, j, i;
    ensures \true; // No specific postcondition provided as the function does not return a value or have a clear effect.
*/
void foo252() {

    int i;
    int j;
    int a;
    int b;

    a = 0;
    b = 0;
    j = 1;
    i = 0;

    /*@
        loop invariant a >= 0;
        loop invariant b >= 0;
        loop invariant i >= 0;
        loop invariant j >= 1;
        loop assigns a, b, i, j;
        loop variant unknown(); // Assuming unknown() eventually terminates the loop.
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
