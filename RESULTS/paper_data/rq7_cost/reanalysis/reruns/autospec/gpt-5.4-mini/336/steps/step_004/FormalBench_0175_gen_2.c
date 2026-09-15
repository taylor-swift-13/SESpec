int maxPrimeFactors(int num);

int maxPrimeFactors(int num) {

		int result = 0;
		/*@
		loop invariant 2 <= c <= num + 1;
		loop invariant 0 <= num;
		loop invariant 0 <= result <= num;
		loop invariant result == 0 || result >= 2;
		loop invariant \forall integer p; 2 <= p < c ==> num % p != 0;
		loop invariant \forall integer p; 2 <= p < c && (num % p == 0) ==> p <= result;
		loop invariant \forall integer p; 2 <= p < c && p * p <= num ==> num % p != 0;
		loop invariant result == 0 || result >= 2;
		loop invariant result <= num;
		loop invariant c <= num + 1;
		loop invariant \forall integer p; 2 <= p < c && p * p <= num ==> num % p != 0;
		loop invariant \forall integer p; 2 <= p < c && (num % p == 0) ==> p <= result;
		loop invariant 2 <= c;
		loop invariant 0 <= result;
		loop invariant 0 <= num;
		loop invariant 0 <= c;
		loop invariant 0 < num;
		loop assigns result;
		loop assigns num;
		loop assigns c;
		*/
		for (int c = 2; c <= num; c++) {
			/*@
			loop invariant result == 0 || result >= 2;
			loop invariant result <= num;
			loop invariant result <= num + 1;
			loop invariant num > 0 ==> result <= num;
			loop invariant c <= num + 1;
			loop invariant \forall integer p; 2 <= p < c ==> num % p != 0;
			loop invariant \forall integer p; 2 <= p < c && p * p <= num ==> num % p != 0;
			loop invariant \forall integer p; 2 <= p < c && num % p == 0 ==> p <= result;
			loop invariant \forall integer p; 2 <= p < c && (num % p == 0) ==> p <= result;
			loop invariant \forall integer k; 2 <= k < c ==> num % k != 0;
			loop invariant \forall integer d; 2 <= d < c ==> num % d != 0;
			loop invariant \forall integer d; 2 <= d < c && num % d == 0 ==> d <= result;
			loop invariant \forall integer d; 2 <= d < c && d*d <= result ==> num % d != 0;
			loop invariant \forall integer d; 2 <= d < c && d * d <= num ==> num % d != 0;
			loop invariant 2 <= c;
			loop invariant 1 <= num;
			loop invariant 0 <= result;
			loop invariant 0 <= num;
			loop invariant 0 < num;
			loop assigns result;
			loop assigns num;
			*/
			while (num % c == 0) {
				result = c;
				num /= c;
			}
		}
		return result;
}
