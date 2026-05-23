/*@
    requires number >= 0;
    ensures \forall integer i; 0 <= i < 32 ==> 
             ((i % 2 == 0) ==> ((\old(number) & (1 << i)) != (number & (1 << i))));
    ensures \forall integer i; 0 <= i < 32 ==> 
             ((i % 2 != 0) ==> ((\old(number) & (1 << i)) == (number & (1 << i))));
    assigns \nothing;
*/
int evenBitToggleNumber(int number);

int evenBitToggleNumber(int number) {

		int result = 0;
		int ret = 0;
		int total = number;
		/*@
		    loop invariant total >= 0;
		    loop invariant 0 <= ret <= 32;
		    loop invariant result == \sum(0 <= k < ret && k % 2 == 0 ? (1 << k) : 0);
		    loop assigns ret, total, result;
		    loop variant total;
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
