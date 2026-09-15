
/*@
  logic integer cat_sum(int* a, integer cat, integer n) =
    n <= 0 ? 0 : cat_sum(a, cat, n - 1) + a[n - 1] * a[cat - (n - 1) - 1];
*/

int foo198(int c) {

		int *arr = (int *)malloc(sizeof(int) * (c + 1));
int arr_len = c + 1;
		arr[0] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant \forall integer k; 1 <= k < cat ==> (\exists integer t; 0 <= t < k);
          loop assigns cat, arr[0..c];
            */
            for (int cat = 1; cat <= c; cat++) {
			arr[cat] = 0;
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant \forall integer k; 0 <= k < n ==> 0 <= cat - k - 1 < cat;
          loop assigns arr[cat], n;
            */
            for (int n = 0; n < cat; n++) {
				arr[cat] += arr[n]
						* arr[cat - n - 1];
			}
            
		}
            
		return arr[c];
}
