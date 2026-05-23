
/* No helper predicates or logic functions are needed for this loop. */

int foo353(int num) {

		int result = 0;
		int max = 0;
		int sum = num;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= result;
          loop invariant (!(\at(num,Pre) > 0)) ==> ((sum == \at(num,Pre))&&(max == 0)&&(result == 0)&&(num == \at(num,Pre)));
          loop invariant num == \at(num,Pre);
          loop assigns max, sum, result;
            */
            while (sum > 0) {
			if (result % 2 == 1) {
				max |= (1 << result);
			}
			result++;
			sum >>= 1;
		}
            
		return (num | max);
}
