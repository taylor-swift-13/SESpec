
/*@
  logic integer mod10prod(integer start, integer end) =
    start >= end ? 1 : ((start % 10) * mod10prod(start + 1, end)) % 10;
*/

int foo167(int n, int c) {

		int result = 1;
		if (n == c) {
			return 1;
		} else if ((c - n) >= 5) {
			return 0;
		} else {
			
            /*@
          loop invariant c == \at(c,Pre);
          loop invariant n == \at(n,Pre);
          loop assigns index, result;
            */
            for (int index = n + 1; index < c + 1; index++) {
				result = (result * (index % 10)) % 10;
			}
            
			return result % 10;
		}
}
