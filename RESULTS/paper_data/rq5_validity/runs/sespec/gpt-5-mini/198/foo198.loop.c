
/*@ 
  requires c >= 0;
*/
int foo198(int c) {

	int *arr = (int *)malloc(sizeof(int) * (c + 1));
	int arr_len = c + 1;
	arr[0] = 1;
	
    /*@
      loop invariant 0 <= c;
      loop invariant 1 <= arr_len;
    */
    for (int cat = 1; cat <= c; cat++) {
		arr[cat] = 0;
		
        /*@
          loop assigns cat, n, arr[0 .. arr_len-1];
        */
        for (int n = 0; n < cat; n++) {
			arr[cat] += arr[n]
					* arr[cat - n - 1];
		}
        
	}
	return arr[c];
}
