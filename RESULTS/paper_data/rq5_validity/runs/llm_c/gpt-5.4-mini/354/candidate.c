/*@
    assigns \nothing;
    ensures \result == (num | \let even = 0; \let result = 0; \let sum = num; 
                        \result);
*/
int evenBitSetNumber(int num);

 /*@
    assigns \nothing;
    ensures \result == (num | result);
*/
int evenBitSetNumber(int num) {

		int even = 0;
		int result = 0;
		int sum = num;
		/*@
		    loop invariant even >= 0;
		    loop invariant sum >= 0;
		    loop invariant result >= 0;
		    loop assigns even, result, sum;
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
