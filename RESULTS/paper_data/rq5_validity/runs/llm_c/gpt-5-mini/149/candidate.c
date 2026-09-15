int isPrime(int a);

/*@
    requires a >= 2;
    assigns \nothing;
    ensures (\result == 0) <==> (\exists integer k; 2 <= k <= a/2 && a % k == 0);
    ensures (\result == 1) <==> !(\exists integer k; 2 <= k <= a/2 && a % k == 0);
*/
int isPrime(int a) {

		int i = 2;
		int mid = a/2;

		/*@
		    loop invariant 2 <= i && i <= mid + 1;
		    loop invariant \forall integer j; 2 <= j < i ==> a % j != 0;
		    loop assigns i;
		    loop variant mid - i + 1;
		*/
		while (i <= mid) {
			if (a%i == 0)
				return 0;
			i++;
		}
		return 1;
}
