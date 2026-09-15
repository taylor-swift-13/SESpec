
/*@
  assigns \nothing;
  ensures (\at(num,Pre) <= 0) ==> (\result == \at(num,Pre));
  ensures (\at(num,Pre) > 0) ==>
            (\exists integer e;
               e >= 0 &&
               (\at(num,Pre) >> e) <= 0 &&
               \result == \at(num,Pre) | odd_mask_upto(e));
*/
int foo354(int num) {

		int even = 0;
		int result = 0;
		int sum = num;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= even;
          loop invariant sum == \at(num,Pre) >> even;
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
