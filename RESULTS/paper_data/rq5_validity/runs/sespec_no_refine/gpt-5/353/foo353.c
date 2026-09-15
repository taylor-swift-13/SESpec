
/*@
  requires \true;
  assigns \nothing;
  ensures (\old(num) <= 0) ==> (\result == \old(num));
  ensures (\old(num) > 0) ==> (\exists integer r; r >= 0 && (\old(num) >> r) == 0 && \result == (\old(num) | odd_mask(r)));
*/
int foo353(int num) {

		int result = 0;
		int max = 0;
		int sum = num;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (\at(num,Pre) > 0) ==> (sum == (\at(num,Pre) >> result));
          loop invariant (\at(num,Pre) > 0) ==> (result >= 0);
          loop invariant (\at(num,Pre) > 0) ==> (max == odd_mask(result));
          loop invariant (!(\at(num,Pre) > 0)) ==> ((sum == \at(num,Pre))&&(max == 0)&&(result == 0)&&(num == \at(num,Pre)));
          loop invariant num == \at(num,Pre);
          loop assigns max, sum, result;
            */
            while (sum > 0) {
			if (result % 2 == 1) {
				max |= (1 << result);
			}
			result++;
			sum >>= 1;
		}
            
		return (num | max);
}
