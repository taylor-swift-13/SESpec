```c
/*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        
int foo302(int num, int b, int r) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (\at(r,Pre) > 0) ==> (num == \at(num,Pre) * 10);
          loop invariant (\at(r,Pre) > 0) ==> (r == \at(r,Pre) - 1);
          loop invariant (\at(r,Pre) > 0) ==> (((result == 0)&&(r == \at(r,Pre))&&(b == \at(b,Pre))&&(num == \at(num,Pre))) || (result == num / b));
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
}`
