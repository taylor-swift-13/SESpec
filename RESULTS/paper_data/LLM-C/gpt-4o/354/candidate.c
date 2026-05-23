/*@
    requires num >= 0;
    ensures \result >= num;
    ensures \forall integer i; i % 2 == 0 && i >= 0 && (num & (1 << i)) == 0 ==> (\result & (1 << i)) != 0;
    ensures \forall integer i; i % 2 == 1 || i < 0 || (num & (1 << i)) != 0 ==> (\result & (1 << i)) == (num & (1 << i));
    assigns \nothing;
*/
int evenBitSetNumber(int num);

int evenBitSetNumber(int num) {

		int even = 0;
		int result = 0;
		int sum = num;
		/*@
		loop invariant sum >= 0;
		loop invariant even >= 0;
		loop invariant result >= 0;
		loop invariant \forall integer i; 0 <= i < even && i % 2 == 0 && (num & (1 << i)) == 0 ==> (result & (1 << i)) != 0;
		loop invariant \forall integer i; 0 <= i < even && (i % 2 == 1 || (num & (1 << i)) != 0) ==> (result & (1 << i)) == (num & (1 << i));
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
