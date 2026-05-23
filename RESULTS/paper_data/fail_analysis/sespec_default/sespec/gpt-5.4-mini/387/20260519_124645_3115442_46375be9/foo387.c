
/*@ 
  assigns \nothing;
  ensures (\old(r) <= 0) ==> (\result == 0);
*/
int foo387(int num, int c, int r) {

		int ret = 0;
		
        /*@
          loop invariant \true;
          loop invariant c == \at(c,Pre);
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
