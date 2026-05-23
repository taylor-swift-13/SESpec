
/*@
  logic integer pow2(integer n) = (n <= 0 ? 1 : 2 * pow2(n - 1));
*/

int foo353(int num) {

		int result = 0;
		int max = 0;
		int sum = num;
		
            
        /*@
          loop invariant (\at(num,Pre) > 0) ==> (result >= 0);
          loop invariant (\at(num,Pre) > 0) ==> (sum == (num >> result));
          loop invariant (\at(num,Pre) > 0) ==> (num == \at(num,Pre));
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
