
/*@ 
  requires c != 0;
  assigns \nothing;
  ensures \old(r) <= 0 ==> \result == 0;
  ensures \old(r) > 0 ==> r <= \old(r);
  ensures c == \old(c);
*/
int foo388(int num, int c, int r) {

		int result = 0;
		
            
        /*@
          loop invariant r <= \at(r,Pre);
          loop invariant c == \at(c,Pre);
          loop invariant \true;
          loop invariant (\at(r,Pre) > 0) ==> \true;
          loop invariant (\at(r,Pre) > 0) ==> (r <= \at(r,Pre));
          loop invariant (\at(r,Pre) > 0) ==> (result >= 0 || result < 0);
          loop invariant (\at(r,Pre) > 0) ==> (result * c + num == result * c + num);
          loop invariant (\at(r,Pre) > 0) ==> ((result == 0 && r == \at(r,Pre) && c == \at(c,Pre) && num == \at(num,Pre)) || \true);
          loop invariant (!(\at(r,Pre) > 0)) ==> ((result == 0)&&(r == \at(r,Pre))&&(c == \at(c,Pre))&&(num == \at(num,Pre)));
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
