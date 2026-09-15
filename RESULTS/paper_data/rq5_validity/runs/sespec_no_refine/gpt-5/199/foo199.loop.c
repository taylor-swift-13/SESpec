
/*@
  logic integer cat_pref(int* a, integer c, integer n) =
    n <= 0 ? 0 : cat_pref(a, c, n - 1) + a[n - 1] * a[c - (n - 1) - 1];
*/
        

/*@
*/
        


int foo199(int number) {

		int *arr = (int *)malloc(sizeof(int) * (number + 1));
int arr_len = number + 1;
		arr[0] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= c <= number + 1;
          loop invariant arr_len == number + 1;
          loop invariant \valid(arr + (0 .. arr_len - 1));
          loop invariant arr[0] == 1;
          loop invariant \forall integer k; 1 <= k < c ==> arr[k] == cat_pref(arr, k, k);
          loop assigns c, arr[..], n;
            */
            for (int c = 1; c <= number; c++) {
			arr[c] = 0;
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 0 <= n <= c;
              loop invariant arr_len == number + 1;
              loop invariant \valid(arr + (0 .. arr_len - 1));
              loop invariant arr[0] == 1;
              loop invariant \forall integer k; 1 <= k < c ==> arr[k] == cat_pref(arr, k, k);
              loop invariant arr[c] == cat_pref(arr, c, n);
              loop invariant \forall integer k; 0 <= k < n ==> 0 <= c - k - 1 < c;
              loop assigns arr[c], n;
            */
            for (int n = 0; n < c; n++) {
				arr[c] += arr[n]
						* arr[c - n - 1];
			}
            
		}
            
		return arr[number];
}
