
/*@
  logic integer fact_prefix(integer n) =
    (n <= 0) ? 1 : n * fact_prefix(n - 1);
*/

int foo392(int num) {

		int ret = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant num == \at(num,Pre);
          loop assigns number, ret;
            */
            for (int number = 1; number <= num; number++) {
			ret *= number;
		}
            
		int result = (int) (ret % 100);
		return result;
}
