
/*@ 
logic integer fold10(integer i, integer c, integer acc) =
  (i > c) ? acc : fold10(i + 1, c, ((acc * (i % 10)) % 10));
*/
        
int foo333(int n, int c) {

		int result = 1;
		if (n == c) {
			return 1;
		} else if ((c - n) >= 5) {
			return 0;
		} else {
			
            /*@
          loop invariant fold10(var, c, result) == fold10(n + 1, c, 1);
          loop assigns var, result;
            */
            for (int var = n + 1; var < c + 1; var++) {
				result = (result * (var % 10)) % 10;
			}
            
			return result % 10;
		}
}
