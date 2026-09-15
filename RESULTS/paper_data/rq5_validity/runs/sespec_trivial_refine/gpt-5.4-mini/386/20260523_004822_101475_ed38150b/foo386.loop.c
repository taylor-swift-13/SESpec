
/*@
  requires b != 0;
  requires r >= 0;
*/

int foo386(int num, int b, int r) {

		int result = 0;
		
        /*@
          loop invariant r >= 0;
          loop invariant b != 0;
          loop assigns r, num, result;
        */
            while (r > 0) {
			r -= 1;
			num *= 10;
			result = num / b;
			num %= b;
		}
            
		return result;
}
