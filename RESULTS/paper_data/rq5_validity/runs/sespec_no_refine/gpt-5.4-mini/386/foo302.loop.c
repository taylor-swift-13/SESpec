
/*@
  logic integer pow10(integer n) =
    n <= 0 ? 1 : 10 * pow10(n - 1);
*/

int foo302(int num, int b, int r) {

		int result = 0;
		
            
        /*@
          loop invariant (\at(r,Pre) > 0) ==> (0 <= r && r <= \at(r,Pre));
          loop invariant (!(\at(r,Pre) > 0)) ==> ((result == 0)&&(r == \at(r,Pre))&&(b == \at(b,Pre))&&(num == \at(num,Pre)));
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
