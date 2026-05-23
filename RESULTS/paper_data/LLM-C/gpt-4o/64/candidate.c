int unknown();

/*@
    assigns a, b, i, j;
    ensures \true; // No specific postcondition provided
*/
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
        loop invariant a >= 0;
        loop invariant b == \at(b, Pre) + (\at(j, Pre) - \at(i, Pre)) + (a - 1);
        loop invariant i >= 1;
        loop invariant j >= 1;
        loop assigns a, b, i, j;
        loop variant unknown(); // Assuming unknown() eventually terminates
    */
    while (unknown()) {
       a = a + 1;
       b = b + j - i;
       i = i + 2;
       if (i % 2 == 0){
           j = j + 2;
       }
       else{
           j = j + 1;
       }
    }
}
