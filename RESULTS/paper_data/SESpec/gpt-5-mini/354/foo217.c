
/*@ 
  logic integer mask_odd_bits(integer e) =
    e <= 0 ? 0 :
    ( (e-1) % 2 == 1 ? (1 << (e-1)) : 0 ) + mask_odd_bits(e-1);
*/

/*@
  predicate result_eq_masked(integer orig, integer res, integer e) =
    res == (orig & mask_odd_bits(e));
*/

int foo217(int num) {

		int even = 0;
		int result = 0;
		int sum = num;
		
            
        /*@
          loop invariant 0 <= even;
          loop invariant sum == (\at(num,Pre) >> even);
          loop invariant result == 0 ==> mask_odd_bits(even) == 0;
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
