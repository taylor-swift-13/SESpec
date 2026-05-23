
/*@ 
  logic integer prod_mod10(integer start, integer cur) =
    (cur <= start) ? 1 :
      (((cur - 1) % 10) * prod_mod10(start, cur - 1)) % 10;
*/

int foo333(int n, int c) {

		int result = 1;
		if (n == c) {
			return 1;
		} else if ((c - n) >= 5) {
			return 0;
		} else {
            
            /*@
              loop invariant c == \at(c,Pre);
              loop invariant n == \at(n,Pre);
              loop assigns var, result;
            */
            for (int var = n + 1; var < c + 1; var++) {
				result = (result * (var % 10)) % 10;
			}
            
			return result % 10;
		}
}
