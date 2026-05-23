
/*@
  logic integer power(integer base, integer exp) =
    exp <= 0 ? 1 : base * power(base, exp - 1);
*/

/*@
  logic integer bit_or_shift(integer max, integer result) =
    max | (1 << result);
*/

/*@
  logic integer bit_shift_right(integer sum) =
    sum >> 1;
*/

/*@
  logic integer result_increment(integer result) =
    result + 1;
*/

/*@
  logic integer sum_shift_right(integer sum) =
    sum >> 1;
*/

/*@
  logic integer compute_max(integer max, integer result) =
    (result % 2 == 1) ? (max | (1 << result)) : max;
*/

int foo216(int num) {

		int result = 0;
		int max = 0;
		int sum = num;
		
        /*@
          loop invariant sum == \at(num,Pre) >> result;
          loop invariant result >= 0;
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
