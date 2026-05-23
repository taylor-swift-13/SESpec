
/*@
  logic integer pow10(integer n) = n <= 0 ? 1 : 10 * pow10(n - 1);
  logic integer modpow10(integer x, integer n) = n <= 0 ? x : modpow10(x % 10, n - 1);
  logic integer scaled_num(integer num, integer r) = num * pow10(r);
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
