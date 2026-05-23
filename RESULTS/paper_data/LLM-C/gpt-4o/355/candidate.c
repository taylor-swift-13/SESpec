/*@
    requires num >= 0;
    ensures \result >= num;
    ensures \forall integer i; 0 <= i < 32 && i % 2 == 0 ==> ((num >> i) & 1) == 1 ==> ((\result >> i) & 1) == 1;
    ensures \forall integer i; 0 <= i < 32 && i % 2 == 0 ==> ((num >> i) & 1) == 0 ==> ((\result >> i) & 1) == 1;
    ensures \forall integer i; 0 <= i < 32 && i % 2 == 1 ==> ((\result >> i) & 1) == ((num >> i) & 1);
*/
int evenBitSetNumber(int num) {

		int result = 0;
		int end = 0;
		int sum = num;

		/*@
		    loop invariant sum >= 0;
		    loop invariant result >= 0;
		    loop invariant end >= 0;
		    loop invariant \forall integer i; 0 <= i < result && i % 2 == 0 ==> ((end >> i) & 1) == 1;
		    loop invariant \forall integer i; 0 <= i < result && i % 2 == 1 ==> ((end >> i) & 1) == 0;
		    loop assigns result, end, sum;
		    loop variant sum;
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
