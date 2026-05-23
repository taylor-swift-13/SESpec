
/*@
  // Return 1 iff the k-th bit of n is set, else 0.
  logic integer bit_at(integer n, integer k) = (n >> k) % 2;

  // Mask of all odd bit positions < e, reflecting the loop's update rule.
  logic integer odd_mask_upto(integer e) =
    (e <= 0) ? 0 :
    ((e % 2 == 1 ? (1 << (e - 1)) : 0) + odd_mask_upto(e - 1));
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
