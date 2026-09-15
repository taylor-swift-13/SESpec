/*@
    requires num >= 0;
    assigns \nothing;
    logic integer bitlen(integer x) = (x == 0 ? 0 : 1 + bitlen(x >> 1));
    ensures \result == num | (\sum integer k; 0 <= k < bitlen(num) && k % 2 == 1; (1 << k));
*/
int evenBitSetNumber(int num) {

		int even = 0;
		int result = 0;
		int sum = num;
		/*@
		    loop invariant sum == num >> even;
		    loop invariant even >= 0;
		    loop invariant 0 <= result;
		    loop invariant \forall integer j; 0 <= j < even ==>
		        ((j % 2 == 1) ? (((result >> j) & 1) == 1) : (((result >> j) & 1) == 0));
		    loop assigns even, sum, result;
		    loop variant sum;
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
