/*@
    requires \true;
    assigns \nothing;
    behavior nonpositive:
      assumes num <= 0;
      ensures \result == num;
    behavior positive:
      assumes num > 0;
      ensures \exists integer k;
                k >= 0 &&
                (num >> k) == 0 &&
                (\forall integer t; 0 <= t < k ==> (num >> t) > 0) &&

                /* For bits below k: odd positions are set to 1, even positions unchanged */
                (\forall integer j; 0 <= j < k && (j % 2) == 1 ==> (((\result >> j) & 1) == 1)) &&
                (\forall integer j; 0 <= j < k && (j % 2) == 0 ==> (((\result >> j) & 1) == (((num >> j) & 1)))) &&

                /* For bits at or above k: unchanged */
                (\forall integer j; j >= k ==> (((\result >> j) & 1) == (((num >> j) & 1))));
    complete behaviors nonpositive, positive;
    disjoint behaviors nonpositive, positive;
*/
int evenBitSetNumber(int num);

int evenBitSetNumber(int num) {

		int result = 0;
		int max = 0;
		int sum = num;
		/*@
		    loop invariant 0 <= result;
		    loop invariant 0 <= sum;
		    loop invariant (sum == (num >> result));
		    /* max has ones only at odd positions < result, zeros at even positions < result, and zeros at >= result */
		    loop invariant (\forall integer j; 0 <= j < result && (j % 2) == 1 ==> (((max >> j) & 1) == 1));
		    loop invariant (\forall integer j; 0 <= j < result && (j % 2) == 0 ==> (((max >> j) & 1) == 0));
		    loop invariant (\forall integer j; j >= result ==> (((max >> j) & 1) == 0));
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
