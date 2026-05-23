
/*@
  ensures (\old(num) <= 0) ==> (\result == \old(num));
  ensures (\old(num) > 0) ==> (shifted_prefix(\old(num), result, sum) && odd_mask_up_to(result, end) && sum == 0 && result == shift_count(\old(num)) && \result == (\old(num) | end));
  assigns \nothing;
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
