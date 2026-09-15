/*@
    requires number >= 0;
    ensures \result >= 0;
    ensures \forall integer k; 0 <= k < 32 && k % 2 == 0 ==> 
             ((number & (1 << k)) == 0 <==> (\result & (1 << k)) != 0) &&
             ((number & (1 << k)) != 0 <==> (\result & (1 << k)) == 0);
    ensures \forall integer k; 0 <= k < 32 && k % 2 != 0 ==> 
             ((number & (1 << k)) == (\result & (1 << k)));
    assigns \nothing;
*/
int evenBitToggleNumber(int number) {

		int i = 0;
		int ret = 0;
		int total = number;
		/*@
		loop invariant total >= 0;
		loop invariant 0 <= ret <= 32;
		loop invariant i >= 0;
		loop invariant \forall integer k; 0 <= k < ret && k % 2 == 0 ==> (i & (1 << k)) != 0;
		loop invariant \forall integer k; 0 <= k < ret && k % 2 != 0 ==> (i & (1 << k)) == 0;
		loop assigns i, ret, total;
		loop variant total;
		*/
		while (total > 0) {
			if (ret % 2 == 0) {
				i = i | (1 << ret);
			}
			ret++;
			total >>= 1;
		}
		return number ^ i;
}
