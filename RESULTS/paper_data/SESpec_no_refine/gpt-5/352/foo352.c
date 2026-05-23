
/*@
  logic integer even_mask(integer k) =
    k <= 0 ? 0 : ( ((k - 1) % 2 == 0 ? (1 << (k - 1)) : 0) ) | even_mask(k - 1);
*/

/*@
  requires \true;
  assigns \nothing;
*/
int foo352(int number) {

		int result = 0;
		int ret = 0;
		int total = number;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (!(\at(number,Pre) > 0)) ==> ((total == \at(number,Pre))&&(ret == 0)&&(result == 0)&&(number == \at(number,Pre)));
          loop invariant number == \at(number,Pre);
          loop assigns result, total, ret;
            */
            while (total > 0) {
			if (ret % 2 == 0) {
				result = result | (1 << ret);
			}
			ret++;
			total >>= 1;
		}
            
		return number ^ result;
}
