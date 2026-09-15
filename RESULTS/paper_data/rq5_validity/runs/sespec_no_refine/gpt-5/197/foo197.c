
/*@ logic integer catalan(integer m) =
      m <= 0 ? 1 : \sum(integer j=0, m-1) (catalan(j) * catalan(m - j - 1)); */
/*@
  requires n >= 0;
  assigns \nothing;
  ensures \result == catalan(n);
*/
int foo197(int n) {

		int *arr = (int *)malloc(sizeof(int) * (n + 1));
int arr_len = n + 1;
		arr[0] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= c <= n + 1;
          loop invariant \forall integer i; 0 <= i < c ==> arr[i] == cat_val(arr, i);
          loop assigns c, arr[..], k;
            */
            for (int c = 1; c <= n; c++) {
			arr[c] = 0;
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= k <= c;
          loop invariant arr[c] == \sum(integer j=0, k-1) (arr[j] * arr[c-j-1]);
          loop assigns arr[c], k;
            */
            for (int k = 0; k < c; k++) {
				arr[c] += arr[k]
						* arr[c - k - 1];
			}
            
		}
            
		return arr[n];
}
