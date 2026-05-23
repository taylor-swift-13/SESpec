
/*@ 
  logic integer pow10(integer k) =
    k <= 0 ? 1 : 10 * pow10(k-1);
*/

/*@
  requires \true;
  ensures \true;
*/
int foo387(int num, int c, int r) {

		int ret = 0;
		
            
        /*@
          loop invariant (\at(r,Pre) > 0) ==> ( \at(r,Pre) - r >= 0 );
          loop invariant (!(\at(r,Pre) > 0)) ==> ((ret == 0)&&(r == \at(r,Pre))&&(c == \at(c,Pre))&&(num == \at(num,Pre)));
          loop invariant c == \at(c,Pre);
          loop assigns r, num, ret;
            */
            while (r > 0) {
			r -= 1;
			num *= 10;
			ret = num / c;
			num %= c;
		}
            
		return ret;
}
