int evenPowerSum(int p);

int evenPowerSum(int p) {

		int even = 0;
		/*@
		loop invariant 1 <= c <= p + 1;
		loop invariant even >= 0;
		loop invariant even % 16 == 0;
		loop invariant c - 1 <= p;
		loop invariant \forall integer k; 1 <= k < c ==> (2 * k) * (2 * k) * (2 * k) * (2 * k) >= 0;
		loop invariant even == \sum(integer k = 1; k < c; k++) ((2 * k) * (2 * k) * (2 * k) * (2 * k));
		loop invariant even == \sum(integer k = 1; k < c; (2*k)*(2*k)*(2*k)*(2*k));
		loop invariant even == \sum(integer k = 1; k < c; (2 * k) * (2 * k) * (2 * k) * (2 * k));
		loop invariant even == \sum(integer k = 1; k < c; ((2 * k) * (2 * k) * (2 * k) * (2 * k)));
		loop invariant even == \sum(integer k = 1; k < c) ((2 * k) * (2 * k) * (2 * k) * (2 * k));
		loop invariant even == \sum(integer k = 1, c - 1, (2 * k) * (2 * k) * (2 * k) * (2 * k));
		loop invariant even == \sum(integer k = 1, c - 1) (2 * k * 2 * k * 2 * k * 2 * k);
		loop invariant even == 16 * \sum(integer k = 1; k < c; k++) (k*k*k*k);
		loop invariant even % 16 == 0;
		loop invariant c <= p + 1;
		loop invariant c - 1 <= p;
		loop invariant \forall integer k; 1 <= k < c ==> even >= (2*k)*(2*k)*(2*k)*(2*k);
		loop invariant \forall integer k; 1 <= k < c ==> (2*k)*(2*k)*(2*k)*(2*k) >= 0;
		loop invariant \forall integer k; 1 <= k < c ==> (2 * k) * (2 * k) * (2 * k) * (2 * k) >= 0;
		loop invariant \exists integer k; 0 <= k < c ==> even == \sum(integer i; 1 <= i < c; (2*i)*(2*i)*(2*i)*(2*i));
		loop invariant 1 <= c;
		loop invariant 0 <= p;
		loop invariant 0 <= even;
		loop invariant 0 <= c;
		loop invariant 0 < c;
		loop assigns even;
		loop assigns c;
		*/
		for (int c = 1; c <= p; c++) {
			int tmp = 2 * c;
			even = even + (tmp * tmp * tmp * tmp);
		}
		return even;
}
