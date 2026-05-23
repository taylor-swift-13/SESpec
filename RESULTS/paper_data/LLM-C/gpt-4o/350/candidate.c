/*@
    requires num >= 0;
    ensures \forall integer i; 0 <= i < 32 ==> 
        ((i % 2 == 0) ==> ((\old(num) & (1 << i)) != 0 ==> (\result & (1 << i)) == 0) &&
                          ((\old(num) & (1 << i)) == 0 ==> (\result & (1 << i)) != 0)) &&
        ((i % 2 != 0) ==> ((\old(num) & (1 << i)) == (\result & (1 << i))));
    assigns \nothing;
*/
int evenBitToggleNumber(int num) {

		int result = 0;
		int ret = 0;
		int total = num;
		/*@
		    loop invariant total >= 0;
		    loop invariant result >= 0;
		    loop invariant ret >= 0;
		    loop invariant \forall integer i; 0 <= i < ret ==> 
		        ((i % 2 == 0) ==> ((\old(num) & (1 << i)) != 0 ==> (result & (1 << i)) != 0) &&
		                          ((\old(num) & (1 << i)) == 0 ==> (result & (1 << i)) == 0)) &&
		        ((i % 2 != 0) ==> ((result & (1 << i)) == 0));
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
		return num ^ result;
}
