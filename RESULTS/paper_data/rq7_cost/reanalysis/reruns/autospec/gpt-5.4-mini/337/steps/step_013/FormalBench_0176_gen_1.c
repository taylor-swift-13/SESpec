int maxPrimeFactors(int num);

int maxPrimeFactors(int num) {

		int ret = 0;
		/*@
		loop invariant ret == 0 || ret >= 2;
		loop invariant ret == 0 || ret <= num;
		loop invariant ret == 0 || ret <= j;
		loop invariant ret == 0 || num % ret == 0;
		loop invariant ret == 0 || (\exists integer k; 2 <= k < j && ret == k);
		loop invariant ret == 0 ==> num > 1;
		loop invariant ret == 0 ==> \forall integer k; 2 <= k < j ==> num % k != 0;
		loop invariant ret <= num;
		loop invariant ret <= num + 1;
		loop invariant ret < num + 1;
		loop invariant ret != 0 ==> ret >= 2;
		loop invariant ret != 0 ==> ret == j || ret < j;
		loop invariant ret != 0 ==> ret <= num;
		loop invariant ret != 0 ==> ret <= j;
		loop invariant ret != 0 ==> ret < j || ret == j;
		loop invariant ret != 0 ==> ret % j == 0 || ret >= j;
		loop invariant ret != 0 ==> ret % j == 0 || ret < j;
		loop invariant ret != 0 ==> num % ret == 0;
		loop invariant ret != 0 ==> \forall integer k; 2 <= k < j ==> num % k != 0;
		loop invariant ret != 0 ==> \exists integer k; 2 <= k <= j && ret == k;
		loop invariant ret != 0 ==> \exists integer k; 2 <= k < j && ret == k;
		loop invariant j <= num + 1;
		loop invariant \forall integer p; 2 <= p < j ==> num % p != 0;
		loop invariant \forall integer k; 2 <= k < j ==> ret >= k || num % k != 0;
		loop invariant \forall integer k; 2 <= k < j ==> ret == 0 || ret >= k;
		loop invariant \forall integer k; 2 <= k < j ==> ret == 0 || ret <= k || num % k != 0;
		loop invariant \forall integer k; 2 <= k < j ==> ret == 0 || num % k != 0;
		loop invariant \forall integer k; 2 <= k < j ==> ret % k == 0 || ret == 0;
		loop invariant \forall integer k; 2 <= k < j ==> ret % k != 0;
		loop invariant \forall integer k; 2 <= k < j ==> num % k != 0;
		loop invariant \forall integer k; 2 <= k < j ==> num % k != 0 || ret >= k;
		loop invariant \forall integer k; 2 <= k < j ==> (num % k != 0 || ret >= k);
		loop invariant \forall integer k; 2 <= k < j && k > 1 ==> num % k != 0;
		loop invariant 2 <= j;
		loop invariant 1 < j;
		loop invariant 0 <= ret;
		loop invariant 0 < num;
		loop assigns ret;
		loop assigns num;
		loop assigns j;
		*/
		for (int j = 2; j <= num; j++) {
			/*@
			loop invariant 2 <= j <= num + 1;
			loop invariant ret == 0 || ret >= 2;
			loop invariant ret == 0 || ret <= num;
			loop invariant ret == 0 || num % ret == 0;
			loop invariant ret != 0 ==> ret <= j;
			loop invariant ret != 0 ==> ret <= num;
			loop invariant ret != 0 ==> num % ret == 0;
			loop invariant ret != 0 ==> \exists integer k; 2 <= k < j && ret == k;
			loop invariant \forall integer k; 2 <= k < j ==> num % k != 0;
			loop invariant \forall integer k; 2 <= k < j ==> ret == 0 || num % k != 0;
			loop invariant ret == 0 || ret >= 2;
			loop invariant ret == 0 || ret <= num;
			loop invariant ret == 0 || ret <= j;
			loop invariant ret == 0 || num % ret == 0;
			loop invariant ret == 0 || (\exists integer k; 2 <= k < j && ret == k);
			loop invariant ret == 0 ==> num > 1;
			loop invariant ret == 0 ==> \forall integer k; 2 <= k < j ==> num % k != 0;
			loop invariant ret <= num;
			loop invariant ret <= num + 1;
			loop invariant ret < num + 1;
			loop invariant ret != 0 ==> ret >= 2;
			loop invariant ret != 0 ==> ret == j || ret < j;
			loop invariant ret != 0 ==> ret <= num;
			loop invariant ret != 0 ==> ret <= j;
			loop invariant ret != 0 ==> ret < j || ret == j;
			loop invariant ret != 0 ==> ret % j == 0 || ret < j;
			loop invariant ret != 0 ==> num % ret == 0;
			loop invariant ret != 0 ==> \exists integer k; 2 <= k <= j && ret == k;
			loop invariant ret != 0 ==> \exists integer k; 2 <= k < j && ret == k;
			loop invariant j <= num + 1;
			loop invariant \forall integer p; 2 <= p < j ==> num % p != 0;
			loop invariant \forall integer k; 2 <= k < j ==> ret >= k || num % k != 0;
			loop invariant \forall integer k; 2 <= k < j ==> ret == 0 || ret >= k;
			loop invariant \forall integer k; 2 <= k < j ==> ret == 0 || num % k != 0;
			loop invariant \forall integer k; 2 <= k < j ==> ret % k == 0 || ret == 0;
			loop invariant \forall integer k; 2 <= k < j ==> ret % k != 0;
			loop invariant \forall integer k; 2 <= k < j ==> num % k != 0;
			loop invariant \forall integer k; 2 <= k < j ==> num % k != 0 || ret >= k;
			loop invariant \forall integer k; 2 <= k < j ==> (num % k != 0 || ret >= k);
			loop invariant \forall integer k; 2 <= k < j && k > 1 ==> num % k != 0;
			loop invariant 2 <= j;
			loop invariant 1 < j;
			loop invariant 0 <= ret;
			loop invariant 0 < num;
			loop assigns ret;
			loop assigns num;
			*/
			while (num % j == 0) {
				ret = j;
				num /= j;
			}
		}
		return ret;
}
