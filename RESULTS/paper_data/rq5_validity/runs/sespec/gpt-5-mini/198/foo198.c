
/*@ logic integer catalan(integer k) =
      k == 0 ? 1 : (k > 0 ? (\sum integer n; 0 <= n < k; catalan(n) * catalan(k - 1 - n)) : 0);
*/
/*@
  requires c >= 0;
  assigns \nothing;
  ensures \result == catalan(c);
  ensures c >= 0 ==> \result > 0;
*/
int foo198(int c) {

	int *arr = (int *)malloc(sizeof(int) * (c + 1));
	int arr_len = c + 1;
	arr[0] = 1;
	
    /*@
      loop invariant 0 <= c;
      loop invariant 1 <= arr_len;
      loop invariant 1 <= cat + 1 <= arr_len;
      loop invariant (\forall integer i; 0 <= i < cat ==> arr[i] == catalan(i));
      loop assigns cat, arr[0 .. arr_len-1];
    */
    for (int cat = 1; cat <= c; cat++) {
		arr[cat] = 0;
		
        /*@
          loop assigns n, arr[0 .. arr_len-1];
          loop invariant 0 <= n <= cat;
          loop invariant arr[cat] == (\sum integer m; 0 <= m < n; arr[m] * arr[cat - m - 1]);
        */
        for (int n = 0; n < cat; n++) {
			arr[cat] += arr[n]
					* arr[cat - n - 1];
		}
        
	}
	return arr[c];
}
