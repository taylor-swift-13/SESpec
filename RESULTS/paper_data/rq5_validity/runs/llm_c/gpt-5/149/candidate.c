int isPrime(int a);

/*@ 
  requires a >= 2;
  assigns \nothing;
  ensures (\result == 1) <==> (\forall integer k; 2 <= k <= a/2 ==> a % k != 0);
  ensures \result == 0 || \result == 1;
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
		/*@ assert \forall integer k; 2 <= k <= mid ==> a % k != 0; */
		return 1;
}
