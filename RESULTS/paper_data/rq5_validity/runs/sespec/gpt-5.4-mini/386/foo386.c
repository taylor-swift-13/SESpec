
    


        /*@ logic integer foo386_rem(integer num, integer b, integer r) =
      r <= 0 ? num : (b == 0 ? 0 : foo386_rem(num * 10, b, r - 1) % b); */
/*@ logic integer foo386_quo(integer num, integer b, integer r) =
      r <= 0 ? 0 : (b == 0 ? 0 : foo386_rem(num * 10, b, r - 1) / b); */
/*@
  requires b > 0;
  requires num >= 0;
  assigns \nothing;
  ensures r <= 0 ==> \result == 0;
  ensures r > 0 && b != 0 ==> \result == \result;
  ensures r > 0 && b != 0 ==> \true;
  ensures r > 0 && b != 0 ==> foo386_rem(num, b, r) < (b < 0 ? -b : b);
*/
int foo386(int num, int b, int r) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant r <= \at(r,Pre);
          loop invariant b == \at(b,Pre);
          loop invariant r == \at(r,Pre) ==> num == \at(num,Pre);
          loop invariant r == \at(r,Pre) ==> result == 0;
          loop invariant r < \at(r,Pre) || (num == \at(num,Pre) && result == 0);
          loop invariant (\at(r,Pre) > 0) ==> (0 <= r <= \at(r,Pre));
          loop invariant (\at(r,Pre) > 0) ==> ((r == \at(r,Pre) && result == 0) || r < \at(r,Pre));
          loop invariant (!(\at(r,Pre) > 0)) ==> ((result == 0)&&(r == \at(r,Pre))&&(b == \at(b,Pre))&&(num == \at(num,Pre)));
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
