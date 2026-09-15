int evenPowerSum(int p);

int evenPowerSum(int p) {

		int odd = 0;
		/*@
		>>> INFILL <<<
		loop invariant odd == \sum(integer k = 1, c - 1) (2 * k) * (2 * k) * (2 * k) * (2 * k);
		loop invariant odd == \sum(integer k = 1, c - 1) (2 * k * 2 * k * 2 * k * 2 * k);
		loop invariant odd == \sum(integer k = 1, c - 1) (16 * k * k * k * k);
		loop invariant odd == \sum(integer i, 1, c-1, (2*i)*(2*i)*(2*i)*(2*i));
		loop invariant odd == \sum(integer i = 1, c - 1) (2 * i * 2 * i * 2 * i * 2 * i);
		loop invariant odd == 16 * \sum(integer k = 1, c - 1) (k * k * k * k);
		loop invariant odd % 16 == 0;
		loop invariant c <= p + 1;
		loop invariant c - 1 <= p;
		loop invariant \forall integer k; 1 <= k < c ==> odd >= 16 * k * k * k * k;
		loop invariant \exists integer k; 0 <= k < c ==> odd >= 16 * k * k * k * k;
		loop invariant 1 <= c;
		loop invariant 0 <= odd;
		loop invariant 0 <= c;
		loop invariant 0 < c;
		loop assigns odd;
		loop assigns c;
		*/
		for (int c = 1; c <= p; c++) {
			int tmp = 2 * c;
			odd = odd + (tmp * tmp * tmp * tmp);
		}
		return odd;
}
