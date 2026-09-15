
/* (Note: removed malformed annotation lines) */

int foo351(int number) {

		int i = 0;
		int ret = 0;
		int total = number;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (\at(number,Pre) > 0) ==> (0 <= ret);
          loop invariant (\at(number,Pre) > 0) ==> (total == (\at(number,Pre) >> ret));
          loop invariant (!(\at(number,Pre) > 0)) ==> ((total == \at(number,Pre))&&(ret == 0)&&(i == 0)&&(number == \at(number,Pre)));
          loop invariant number == \at(number,Pre);
          loop assigns i, total, ret;
            */
            while (total > 0) {
			if (ret % 2 == 0) {
				i = i | (1 << ret);
			}
			ret++;
			total >>= 1;
		}
            
		return number ^ i;
}
