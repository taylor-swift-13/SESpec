
/*@
  requires c != 0;
  requires r >= 0;
*/
        
int foo387(int num, int c, int r) {

		int ret = 0;
		
        /*@
          loop assigns r, num, ret;
          loop invariant r >= 0;
          loop invariant c != 0;
        */
            while (r > 0) {
			r -= 1;
			num *= 10;
			ret = num / c;
			num %= c;
		}
            
		return ret;
}
