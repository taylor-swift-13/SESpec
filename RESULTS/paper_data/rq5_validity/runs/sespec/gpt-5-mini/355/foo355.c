
/*@
  logic integer sum_odd_bits_upto{L}(integer k) =
    k <= 0 ? 0 :
    ( ( (k - 1) % 2 == 1) ? (1 << (k-1)) : 0 ) + sum_odd_bits_upto{L}(k-1);
*/

int foo355(int num) {

		int result = 0;
		int end = 0;
		int sum = num;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
        /*@
          loop invariant (\at(num,Pre) > 0) ==> (sum >= 0);
          loop invariant (\at(num,Pre) > 0) ==> (result >= 0);
          loop invariant (!(\at(num,Pre) > 0)) ==> ((sum == \at(num,Pre))&&(end == 0)&&(result == 0)&&(num == \at(num,Pre)));
          loop invariant sum == \at(num,Pre) || sum >= 0;
          loop invariant num == \at(num,Pre);
          loop assigns end, sum, result;
        */
            while (sum > 0) {
			if (result % 2 == 1) {
				end |= (1 << result);
			}
			result++;
			sum >>= 1;
		}
            
		return (num | end);
}
