
/*@
  logic integer product_mod_10(integer start, integer end) =
    (start > end) ? 1 : (start % 10) * product_mod_10(start + 1, end) % 10;
*/

/*@
  requires \at(b,Pre) - \at(a,Pre) < 5 && \at(a,Pre) != \at(b,Pre);
  ensures \result == product_mod_10(\at(a,Pre) + 1, \at(b,Pre)) % 10;
*/
int foo174(int a, int b) {
    int variable = 1;
    if (a == b) {
        return 1;
    } else if ((b - a) >= 5) {
        return 0;
    } else {
        /*@
          loop invariant b == \at(b,Pre);
          loop invariant a == \at(a,Pre);
          loop assigns i, variable;
        */
        for (int i = a + 1; i < b + 1; i++) {
            variable = (variable * (i % 10)) % 10;
        }
        return variable % 10;
    }
}
