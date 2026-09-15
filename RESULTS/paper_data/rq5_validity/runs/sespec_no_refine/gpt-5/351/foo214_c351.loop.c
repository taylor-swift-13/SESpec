
/*@
  logic integer pow2(integer e) = (e <= 0 ? 1 : 2 * pow2(e - 1));

  // Lowbits(e) = (1 << e) - 1 for e >= 0
  logic integer lowbits(integer e) = (e <= 0 ? 0 : pow2(e) - 1);

  // Mask of even bit positions (0,2,4,...) in 32-bit words
  logic integer even_mask = 0x55555555;
*/

/*@
  requires \true;
*/
int foo214_c351(int number) {

		int i = 0;
		int ret = 0;
		int total = number;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (\at(number,Pre) > 0) ==> ((0 <= ret) && (total == (\at(number,Pre) >> ret)));
          loop invariant (\at(number,Pre) > 0) ==> (0 <= ret);
          loop invariant (!(\at(number,Pre) > 0)) ==> ((total == \at(number,Pre))&&(ret == 0)&&(i == 0)&&(number == \at(number,Pre)));
          loop invariant number == \at(number,Pre);
          loop assigns i, total, ret;
            */
            while (total > 0) {
			if (ret % 2 == 0) {
				i = i | (1 << ret);
			}
			ret++;
			total >>= 1;
		}
            
		return number ^ i;
}
