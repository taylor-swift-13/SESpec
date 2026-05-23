
/*@ logic integer pow2(integer n) = n <= 0 ? 1 : 2 * pow2(n - 1); */

/*@
  ensures !(\at(num,Pre) > 0) ==> (\result == \at(num,Pre));
  assigns \nothing;
*/
int foo218(int num) {

		int result = 0;
		int end = 0;
		int sum = num;
		
            /*@
          loop invariant (\at(num,Pre) > 0) ==> (0 <= result && sum >= 0);
          loop invariant (!(\at(num,Pre) > 0)) ==> ((sum == \at(num,Pre))&&(end == 0)&&(result == 0)&&(num == \at(num,Pre)));
          loop invariant (\at(num,Pre) > 0) ==> (num == \at(num,Pre));
          loop invariant num == \at(num,Pre);
          loop assigns end, sum, result;
            */
            while (sum > 0) {
			if (result % 2 == 1) {
				end |= (1 << result);
			}
			result++;
			sum >>= 1;
		}
            
		return (num | end);
}
