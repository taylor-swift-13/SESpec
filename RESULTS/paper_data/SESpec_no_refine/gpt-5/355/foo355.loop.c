
/*@
  // number of right shifts needed to reduce a nonnegative integer to zero
  logic integer shift_count(integer n) = (n <= 0) ? 0 : 1 + shift_count(n >> 1);

  // sum equals the initial number right-shifted by 'result' steps, while within bounds
  predicate shifted_prefix(integer n, integer result, integer sum) =
    0 <= result && result <= shift_count(n) && sum == (n >> result);

  // end has bits set exactly at odd positions below 'result'
  predicate odd_mask_up_to(integer result, integer end) =
    0 <= result &&
    (\forall integer i; 0 <= i < result ==> ((i % 2 == 1) <==> (((end >> i) & 1) == 1))) &&
    (\forall integer i; i < 0 || i >= result ==> (((end >> i) & 1) == 0));
*/

int foo355(int num) {

		int result = 0;
		int end = 0;
		int sum = num;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
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
