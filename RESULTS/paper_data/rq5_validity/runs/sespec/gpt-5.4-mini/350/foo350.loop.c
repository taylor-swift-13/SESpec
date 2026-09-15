
/*@
logic integer shr(integer x, integer n) =
  n <= 0 ? x : shr(x / 2, n - 1);

logic integer even_mask(integer n) =
  n <= 0 ? 0 :
  even_mask(n - 1) + (((n - 1) % 2 == 0) ? (1 << (n - 1)) : 0);
*/

int foo350(int num) {

		int result = 0;
		int ret = 0;
		int total = num;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (\at(num,Pre) > 0) ==> (0 <= ret);
          loop invariant (\at(num,Pre) > 0) ==> (0 <= total);
          loop invariant (\at(num,Pre) > 0) ==> (total <= \at(num,Pre));
          loop invariant (\at(num,Pre) > 0) ==> (num == \at(num,Pre));
          loop invariant (!(\at(num,Pre) > 0)) ==> ((total == \at(num,Pre))&&(ret == 0)&&(result == 0)&&(num == \at(num,Pre)));
          loop invariant (\at(num,Pre) > 0) ==> (total >= 0);
          loop invariant num == \at(num,Pre);
          loop assigns result, total, ret;
            */
            while (total > 0) {
			if (ret % 2 == 0) {
				result = result | (1 << ret);
			}
			ret++;
			total >>= 1;
		}
            
		return num ^ result;
}
