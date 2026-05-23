
/*@ logic integer selected_even_bits(integer x) =
      x <= 0 ? 0 : ((x % 2 == 1) ? 1 : 0) + 4 * selected_even_bits(x / 4); */
/*@
   assigns \nothing;
   ensures num <= 0 ==> \result == num;
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
