
/*@
  logic integer cat_partial(int* a, integer m, integer t) =
    t <= 0 ? 0 : cat_partial(a, m, t - 1) + a[t - 1] * a[m - t];
*/

/*@
*/
int foo198(int c) {

		int *arr = (int *)malloc(sizeof(int) * (c + 1));
int arr_len = c + 1;
		arr[0] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= cat <= c + 1;
          loop invariant \valid(arr + (0 .. arr_len-1));
          loop invariant arr_len == c + 1;
          loop invariant arr[0] == 1;
          loop invariant \forall integer m; 1 <= m < cat ==> arr[m] == cat_partial(arr, m, m);
          loop assigns cat, arr[..], n;
            */
            for (int cat = 1; cat <= c; cat++) {
			arr[cat] = 0;
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 0 <= n <= cat;
              loop invariant \valid(arr + (0 .. arr_len-1));
              loop invariant arr_len == c + 1;
              loop invariant arr[0] == 1;
              loop invariant \forall integer m; 1 <= m < cat ==> arr[m] == cat_partial(arr, m, m);
              loop invariant arr[cat] == cat_partial(arr, cat, n);
              loop assigns arr[cat], n;
            */
            for (int n = 0; n < cat; n++) {
				arr[cat] += arr[n]
						* arr[cat - n - 1];
			}
            
		}
            
		return arr[c];
}
