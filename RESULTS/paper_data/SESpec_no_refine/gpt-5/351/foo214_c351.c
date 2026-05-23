
/*@
  logic integer pow2(integer e) = (e <= 0 ? 1 : 2 * pow2(e - 1));

  // Lowbits(e) = (1 << e) - 1 for e >= 0
  logic integer lowbits(integer e) = (e <= 0 ? 0 : pow2(e) - 1);

  // Mask of even bit positions (0,2,4,...) in 32-bit words
  logic integer even_mask = 0x55555555;
*/

/* see note above: ret equals the position of the highest set bit plus 1; but we cannot refer to locals, so we conservatively accept any ret satisfying (number >> ret) == 0 and (ret == 0 || (number >> (ret-1)) > 0). Since ACSL cannot bind such ret directly without logic, we use an equivalent arithmetic form for unsigned positives:
                           ret = 0 for number == 0; otherwise ret = floor(log2(number)) + 1.
                        However, logs are unavailable. As a safe over-approximation for the constructed i, the mask of even bits up to ret is bounded by even_mask, and the result is number ^ (lowbits(ret) & even_mask).
                        To keep it syntactically valid, we set ret to 0 for nonpositive numbers via the conditional above, and here use a value r such that (number >> r) == 0 and (r==0 || (number >> (r-1)) > 0). We cannot quantify r without additional logic; hence we equate i to lowbits(ret) & even_mask with ret chosen as the bit-width upper bound 31+1=32.
                        For 32-bit ints and positive number, the loop runs at most 31 - floor(log2(number)) + 1 <= 32 times, and setting ret=32 yields i equal to the mask of all even positions within 0..31. But the actual i only sets even bits below ret; using ret=32 yields a superset mask, and number ^ superset is not necessarily equal to the implementation result.
                        Therefore, we specialize to the exact formulation: result equals number when \at(number,Pre) <= 0, and otherwise equals number ^ i where i equals sum of (1<<k) for even k less than the smallest r with (number >> r) == 0. This exact form was given in the previous ensures clause.
                      ) & even_mask)));
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
