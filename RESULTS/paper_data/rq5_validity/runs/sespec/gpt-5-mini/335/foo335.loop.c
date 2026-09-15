
/*@ 
  logic integer prod_mod10(integer start, integer end) =
    start > end ? 1 : ( ( (start % 10) * prod_mod10(start+1, end) ) % 10 );
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
          loop invariant a + 1 <= i <= \at(b,Pre)  ||  !(i < \at(b,Pre) + 1);
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
