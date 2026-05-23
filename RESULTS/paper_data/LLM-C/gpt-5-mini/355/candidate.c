int evenBitSetNumber(int num);

/*@
    requires num >= 0;
    assigns \nothing;
    ensures \exists integer m;
        m >= 0 &&
        (num >> m) == 0 &&
        (m == 0 || (num >> (m-1)) != 0) &&
        (\forall integer k; 0 <= k < m ==>
            ((k % 2 == 1) ==> (((\result >> k) & 1) == 1)) &&
            ((k % 2 == 0) ==> (((\result >> k) & 1) == (((num >> k) & 1)))))
        &&
        (\forall integer k; k >= m ==> (((\result >> k) & 1) == (((num >> k) & 1))));
*/
int evenBitSetNumber(int num) {

		int result = 0;
		int end = 0;
		int sum = num;
		/*@
		    loop invariant 0 <= result <= 8 * (int)sizeof(int);
		    loop invariant sum >= 0;
		    loop invariant sum == (num >> result);
		    loop invariant \forall integer k; 0 <= k < result ==>
		        ((k % 2 == 1) ==> (((end >> k) & 1) == 1)) &&
		        ((k % 2 == 0) ==> (((end >> k) & 1) == 0));
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
