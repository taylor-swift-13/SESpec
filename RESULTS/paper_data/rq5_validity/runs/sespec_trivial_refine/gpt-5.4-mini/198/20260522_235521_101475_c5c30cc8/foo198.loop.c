
        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        

/*@
  requires 0 <= c;
  requires c < INT_MAX;
*/

int foo198(int c) {

		int *arr = (int *)malloc(sizeof(int) * (c + 1));
int arr_len = c + 1;
		arr[0] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= cat <= c + 1;
          loop invariant arr[0] == 1;
          loop invariant \forall integer i; 0 <= i < cat ==> arr[i] >= 0;
          loop assigns cat, n, arr[cat];
            */
            for (int cat = 1; cat <= c; cat++) {
			arr[cat] = 0;
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= n <= cat;
          loop invariant arr[cat] == \sum integer k; 0 <= k < n; arr[k] * arr[cat - k - 1];
          loop assigns n, arr[cat];
            */
            for (int n = 0; n < cat; n++) {
				arr[cat] += arr[n]
						* arr[cat - n - 1];
			}
            
		}
            
		return arr[c];
}
