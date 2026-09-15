
/*@
  logic integer mod_product(integer start, integer end) =
    (start > end) ? 1 : ((start % 10) * mod_product(start + 1, end)) % 10;
*/

/*@
  requires \at(b,Pre) - \at(a,Pre) < 5 && \at(a,Pre) != \at(b,Pre) && 
           (variable == 1) * (b == \at(b,Pre)) * (a == \at(a,Pre));
*/
int foo174(int a, int b) {

    int variable = 1;
    if (a == b) {
        return 1;
    } else if ((b - a) >= 5) {
        return 0;
    } else {
        
        /*@
          loop invariant a + 1 <= i <= b + 1;
          loop invariant variable == mod_product(a + 1, i - 1);
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
