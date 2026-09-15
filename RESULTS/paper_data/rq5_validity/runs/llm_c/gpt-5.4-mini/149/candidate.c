/*@
    assigns \nothing;
    ensures \result == 0 || \result == 1;
    ensures \result == 1 ==> a > 1;
*/
int isPrime(int a);

 /*@
    assigns \nothing;
    ensures \result == 0 || \result == 1;
    ensures a <= 1 ==> \result == 1;
*/
int isPrime(int a) {

		int i = 2;
		int mid = a/2;
		/*@
            loop invariant 2 <= i <= mid + 1;
            loop invariant \forall integer k; 2 <= k < i ==> a % k != 0;
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
