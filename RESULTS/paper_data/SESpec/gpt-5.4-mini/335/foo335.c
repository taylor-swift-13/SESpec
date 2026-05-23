
/*@
  logic integer digit_prod(integer x, integer y) =
    x > y ? 1 : ((x % 10) * digit_prod(x + 1, y)) % 10;
*/

/*@
  requires 0 <= a <= b;
  assigns \nothing;
  ensures a == b ==> \result == 1;
  ensures (b - a) >= 5 ==> \result == 0;
  ensures 0 <= \result && \result <= 9;
*/
int foo335(int a, int b) {

        int variable = 1;
        if (a == b) {
            return 1;
        } else if ((b - a) >= 5) {
            return 0;
        } else {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant a == \at(a,Pre);
          loop invariant b == \at(b,Pre);
          loop invariant i >= \at(a,Pre) + 1;
          loop invariant i <= \at(b,Pre) + 1;
          loop invariant 0 <= variable && variable <= 9;
          loop assigns i, variable;
            */
            for (int i = a + 1; i < b + 1; i++) {
                variable = (variable * (i % 10)) % 10;
            }
            
            return variable % 10;
        }
}
