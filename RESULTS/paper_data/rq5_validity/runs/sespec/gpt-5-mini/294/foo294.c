
/*@ 
  requires p >= 1;
*/
int foo294(int p) {

	int *arr = (int *)malloc(sizeof(int) * (p + 1));
	int arr_len = p + 1;
	arr[0] = 0;
	arr[1] = 1;

	/*@
	  loop invariant 2 <= count <= p + 1;
	  loop invariant arr[0] == 0 && arr[1] == 1;
	  loop invariant \forall integer k; 2 <= k < count ==>
	                   arr[k] == (2 * arr[k-1] + arr[k-2]) % 1000000000;
	  loop invariant (count == p + 1) ==> (\forall integer k; 2 <= k <= p ==>
	                   arr[k] == (2 * arr[k-1] + arr[k-2]) % 1000000000);
	  loop assigns count, arr[0..p];
	*/
	for (int count = 2; count <= p; count++) {
		arr[count] = (2 * arr[count - 1]
				+ arr[count - 2]) % 1000000000;
	}

	return arr[p];
}
