/*@
    requires num >= 0;
    ensures \result >= num;
    ensures \forall integer i; i % 2 == 0 && i >= 0 && (num & (1 << i)) == 0 ==> (\result & (1 << i)) != 0;
    ensures \forall integer i; i % 2 == 1 || (num & (1 << i)) != 0 ==> (\result & (1 << i)) == (num & (1 << i));
    assigns \nothing;
*/
int evenBitSetNumber(int num);

int evenBitSetNumber(int num) {

		int result = 0;
		int max = 0;
		int sum = num;
		/*@
		loop invariant sum >= 0;
		loop invariant result >= 0;
		loop invariant max >= 0;
		loop invariant \forall integer i; 0 <= i < result && i % 2 == 0 && (num & (1 << i)) == 0 ==> (max & (1 << i)) != 0;
		loop invariant \forall integer i; 0 <= i < result && (i % 2 == 1 || (num & (1 << i)) != 0) ==> (max & (1 << i)) == 0;
		loop assigns result, max, sum;
		loop variant sum;
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
