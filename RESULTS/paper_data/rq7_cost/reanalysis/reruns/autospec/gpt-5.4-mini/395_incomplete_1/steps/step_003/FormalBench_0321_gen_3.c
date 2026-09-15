int evenPowerSum(int p);

int evenPowerSum(int p) {

		int odd = 0;
		/*@
		loop invariant 1 <= c <= p + 1;
		loop invariant odd >= 0;
		loop invariant odd % 16 == 0;
		loop invariant \exists integer s; odd == 16 * s;
		loop invariant \forall integer k; 1 <= k < c ==> odd >= (2 * k) * (2 * k) * (2 * k) * (2 * k);
		loop invariant odd == \sum(integer k; 1 <= k < c; (2*k)*(2*k)*(2*k)*(2*k));
		loop invariant odd == \sum(integer k, 1, c-1, (2*k)*(2*k)*(2*k)*(2*k));
		loop invariant odd == \sum(integer k, 1, c - 1, (2 * k) * (2 * k) * (2 * k) * (2 * k));
		loop invariant odd == \sum(integer k = 1; k < c; k++) (2 * k) * (2 * k) * (2 * k) * (2 * k);
		loop invariant odd == \sum(integer k = 1, c - 1) (2 * k) * (2 * k) * (2 * k) * (2 * k);
		loop invariant odd == \sum(integer k = 1, c - 1) (2 * k * 2 * k * 2 * k * 2 * k);
		loop invariant odd % 16 == 0;
		loop invariant c <= p + 1;
		loop invariant c - 1 <= p;
		loop invariant \forall integer k; 1 <= k < c ==> odd >= 16 * k * k * k * k;
		loop invariant \forall integer k; 1 <= k < c ==> odd >= (2*k)*(2*k);
		loop invariant \forall integer k; 1 <= k < c ==> odd >= (2*k)*(2*k)*(2*k)*(2*k);
		loop invariant \exists integer s; odd == s;
		loop invariant \exists integer s; odd == 16*s;
		loop invariant 1 <= c;
		loop invariant 0 <= odd;
		loop invariant 0 <= c;
		loop assigns odd;
		loop assigns c;
		*/
		for (int c = 1; c <= p; c++) {
			int tmp = 2 * c;
			odd = odd + (tmp * tmp * tmp * tmp);
		}
		return odd;
}
