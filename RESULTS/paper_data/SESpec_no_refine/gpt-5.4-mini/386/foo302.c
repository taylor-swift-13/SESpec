
/*@
  assigns r, num, result;
  ensures (\old(r) > 0) ==> (r == 0);
  ensures (\old(r) > 0) ==> (b == \old(b));
  ensures (\old(r) > 0) ==> (num == (((\old(num) * pow10(\old(r))) % \old(b))));
  ensures (\old(r) > 0) ==> (result == (((\old(num) * pow10(\old(r - 1))) / \old(b))));
  ensures (!(\old(r) > 0)) ==> (r == \old(r) && num == \old(num) && b == \old(b) && result == 0);
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
