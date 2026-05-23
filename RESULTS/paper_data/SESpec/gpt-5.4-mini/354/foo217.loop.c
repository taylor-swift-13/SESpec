
/*@
  logic integer pow2(integer n) = (n <= 0) ? 1 : 2 * pow2(n - 1);
*/

int foo217(int num) {

		int even = 0;
		int result = 0;
		int sum = num;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= even;
          loop invariant (\at(num,Pre) > 0) ==> (sum == (\at(num,Pre) >> even));
          loop invariant (!(\at(num,Pre) > 0)) ==> ((sum == \at(num,Pre))&&(result == 0)&&(even == 0)&&(num == \at(num,Pre)));
          loop invariant num == \at(num,Pre);
          loop assigns result, sum, even;
            */
            while (sum > 0) {
			if (even % 2 == 1) {
				result |= (1 << even);
			}
			even++;
			sum >>= 1;
		}
            
		return (num | result);
}
