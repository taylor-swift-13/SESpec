
/*@ logic integer pow2(integer n) = (n <= 0 ? 1 : 2 * pow2(n - 1)); */

int foo352(int number) {

		int result = 0;
		int ret = 0;
		int total = number;
		
        /*@
          loop invariant 0 <= ret;
          loop invariant number == \at(number,Pre);
          loop invariant total == \at(number,Pre) >> ret;
          loop assigns result, total, ret;
        */
            while (total > 0) {
			if (ret % 2 == 0) {
				result = result | (1 << ret);
			}
			ret++;
			total >>= 1;
		}
            
		return number ^ result;
}
