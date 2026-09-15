
/*@
  requires c != 0;
*/
        
int foo388(int num, int c, int r) {

		int result = 0;
		
        /*@
          loop invariant \true;
          loop assigns r, num, result;
        */
            while (r > 0) {
			r -= 1;
			num *= 10;
			result = num / c;
			num %= c;
		}
            
		return result;
}
