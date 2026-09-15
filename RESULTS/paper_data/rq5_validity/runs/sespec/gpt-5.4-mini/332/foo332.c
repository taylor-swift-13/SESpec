
/*@ logic integer prod10(integer a, integer b) =
      b < a ? 1 : (prod10(a, b - 1) * (b % 10)) % 10;
*/
/*@
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
			
            /*@
              loop invariant c == \at(c,Pre);
              loop invariant num == \at(num,Pre);
              loop invariant var == num + 1 || (num + 1 <= var <= c + 1);
              loop invariant (var <= c) ==> (num + 1 <= var <= c + 1);
              loop invariant loop_assigns: \true;
              loop assigns var, result;
            */
            for (int var = num + 1; var < c + 1; var++) {
				result = (result * (var % 10)) % 10;
			}
            
			return result % 10;
		}
}
