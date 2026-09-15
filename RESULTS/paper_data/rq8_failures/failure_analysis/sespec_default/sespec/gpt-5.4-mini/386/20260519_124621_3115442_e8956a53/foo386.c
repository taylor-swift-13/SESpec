
/*@
  assigns \nothing;
*/
int foo386(int num, int b, int r) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant r <= \at(r,Pre);
          loop invariant b == \at(b,Pre);
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
