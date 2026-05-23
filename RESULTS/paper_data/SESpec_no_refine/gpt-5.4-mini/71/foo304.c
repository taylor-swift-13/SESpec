
/*@ 
  assigns r, num, result;
  ensures (\at(r,Pre) > 0) ==> (r == 0);
  ensures (\at(r,Pre) > 0) ==> (result == num / c);
  ensures (\at(r,Pre) > 0) ==> (num == \at(num,Pre) * pow10(\at(r,Pre)) % c);
  ensures (\at(r,Pre) > 0) ==> (c == \at(c,Pre));
  ensures (!(\at(r,Pre) > 0)) ==> (result == 0);
  ensures (!(\at(r,Pre) > 0)) ==> (r == \at(r,Pre));
  ensures (!(\at(r,Pre) > 0)) ==> (num == \at(num,Pre));
  ensures (!(\at(r,Pre) > 0)) ==> (c == \at(c,Pre));
*/
int foo304(int num, int c, int r) {

		int result = 0;
		
            
        /*@
          loop invariant (\at(r,Pre) > 0) ==> (r >= 0);
          loop invariant (!(\at(r,Pre) > 0)) ==> ((result == 0)&&(r == \at(r,Pre))&&(c == \at(c,Pre))&&(num == \at(num,Pre)));
          loop invariant c == \at(c,Pre);
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
