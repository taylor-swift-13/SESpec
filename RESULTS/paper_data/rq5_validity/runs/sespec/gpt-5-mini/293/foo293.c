
/*@ logic integer seq293(integer n) =
      n == 0 ? 0 :
      n == 1 ? 1 :
      (seq293(n-1)*2 + seq293(n-2)) % 1000000000;
*/
/*@
  requires seed == 1;
  
  ensures 0 <= \result && \result < 1000000000;
*/
int foo293(int seed) {

	int *arr = (int *)malloc(sizeof(int) * (seed + 1));
	int arr_len = seed + 1;
	arr[0] = 0;
	arr[1] = 1;

	/*@
	  loop invariant 2 <= p <= seed + 1;
	  loop invariant 0 <= arr[0] < 1000000000;
	  loop invariant 0 <= arr[1] < 1000000000;
	  loop invariant \forall integer k; 2 <= k < p ==>
	                   arr[k] == ((2 * arr[k-1] + arr[k-2]) % 1000000000);
	  loop invariant (!(p <= seed)) ==> (p == seed + 1);
	  loop assigns p, arr[0..seed];
	*/
	for (int p = 2; p <= seed; p++) {
		arr[p] = (2 * arr[p - 1]
				+ arr[p - 2]) % 1000000000;
	}

	return arr[seed];
}
