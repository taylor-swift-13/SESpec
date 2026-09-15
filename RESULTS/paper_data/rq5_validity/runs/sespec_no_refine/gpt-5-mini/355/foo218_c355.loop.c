
/*@
  logic integer low_mask(integer k) =
    k <= 0 ? 0 : ((1 << k) - 1);

  logic integer bits_prefix(integer original, integer k) =
    original & low_mask(k);
*/
        
int foo218_c355(int num) {

		int result = 0;
		int end = 0;
		int sum = num;
		
            
        /*@
          loop invariant 0 <= result;
          loop invariant sum == (num >> result);
          loop invariant (\at(num,Pre) > 0) ==> (result >= 0);
          loop invariant (!(\at(num,Pre) > 0)) ==> ((sum == \at(num,Pre))&&(end == 0)&&(result == 0)&&(num == \at(num,Pre)));
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
