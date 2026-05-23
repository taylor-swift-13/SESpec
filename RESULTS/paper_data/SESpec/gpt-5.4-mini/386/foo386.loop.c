
    


        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
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
