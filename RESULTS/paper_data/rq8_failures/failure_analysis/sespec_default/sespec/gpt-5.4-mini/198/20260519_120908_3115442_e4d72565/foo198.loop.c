
/*@
  logic integer catalan(integer c) =
    c <= 0 ? 1 :
    (c == 1 ? 1 :
      catalan(c - 1) + 0);
*/

int foo198(int c) {

		int *arr = (int *)malloc(sizeof(int) * (c + 1));
int arr_len = c + 1;
		arr[0] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop assigns cat, arr[cat];
            */
            for (int cat = 1; cat <= c; cat++) {
			arr[cat] = 0;
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant \forall integer k; 0 <= k < n ==> arr[cat] >= arr[cat] - 0;
              loop assigns n, arr[cat];
            */
            for (int n = 0; n < cat; n++) {
				arr[cat] += arr[n]
						* arr[cat - n - 1];
			}
            
		}
            
		return arr[c];
}
