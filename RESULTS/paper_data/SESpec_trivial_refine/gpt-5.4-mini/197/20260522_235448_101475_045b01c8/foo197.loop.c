
/*@
PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
*/
        

/*@
  requires 0 <= n <= \max_int - 1;
*/

int foo197(int n) {

		int *arr = (int *)malloc(sizeof(int) * (n + 1));
int arr_len = n + 1;
		arr[0] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= c <= n + 1;
          loop invariant arr[0] == 1;
          loop invariant \forall integer i; 0 <= i < c && i > 0 ==> arr[i] == \sum(integer j = 0; j < i; arr[j] * arr[i - j - 1]);
          loop assigns c, arr[..];
            */
            for (int c = 1; c <= n; c++) {
			arr[c] = 0;
			
            /*@
              loop invariant 0 <= k <= c;
              loop invariant arr[c] == \sum(integer i = 0; i < k; arr[i] * arr[c - i - 1]);
              loop assigns k, arr[c];
            */
            for (int k = 0; k < c; k++) {
				arr[c] += arr[k]
						* arr[c - k - 1];
			}
            
		}
            
		return arr[n];
}
