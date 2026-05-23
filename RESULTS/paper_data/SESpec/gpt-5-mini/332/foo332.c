
/*@ 
  logic integer prod_mod10(integer a, integer b) =
    a >= b ? 1 : ((a % 10) * prod_mod10(a+1, b)) % 10;
*/

/*@
  requires \at(c,Pre) - \at(num,Pre) < 5 && \at(num,Pre) != \at(c,Pre);
  assigns \nothing;
  ensures (num == c) ==> \result == 1;
  ensures ((c - num) >= 5) ==> \result == 0;
*/
int foo332(int num, int c) {

		int result = 1;
		if (num == c) {
			return 1;
		} else if ((c - num) >= 5) {
			return 0;
		} else {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (var < \at(c,Pre) + 1) ==> (\exists integer v0; v0 == \at(num,Pre) + 1 && var >= v0 && var <= \at(c,Pre) + 1);
          loop invariant c == \at(c,Pre);
          loop invariant num == \at(num,Pre);
          loop assigns var, result;
            */
            for (int var = num + 1; var < c + 1; var++) {
				result = (result * (var % 10)) % 10;
			}
            
			return result % 10;
		}
}
