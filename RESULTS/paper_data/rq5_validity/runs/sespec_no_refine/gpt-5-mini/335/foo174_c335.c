
/*@ 
  logic integer prod_mod10(integer lo, integer hi) =
    lo > hi ? 1 : ( (lo % 10) * prod_mod10(lo+1, hi) ) % 10;
*/

/*@
  requires \at(b,Pre) - \at(a,Pre) < 5 && \at(a,Pre) != \at(b,Pre);
  assigns \nothing;
  ensures (a == b) ==> \result == 1;
  ensures (a != b && (b - a) >= 5) ==> \result == 0;
*/
int foo174_c335(int a, int b) {

        int variable = 1;
        if (a == b) {
            return 1;
        } else if ((b - a) >= 5) {
            return 0;
        } else {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
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
