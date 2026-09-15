
/*@
  assigns \nothing;
  ensures (\old(r) <= 0) ==> (\result == 0 && r == \old(r) && b == \old(b) && num == \old(num));
  ensures (\old(r) > 0) ==> (r == 0 && b == \old(b));
*/
int foo386(int num, int b, int r) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (\at(r,Pre) > 0) ==> (0 <= r <= \at(r,Pre));
          loop invariant (\at(r,Pre) > 0) ==> (r == \at(r,Pre) - iters(\at(r,Pre), r));
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
