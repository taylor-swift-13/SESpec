
/*@
predicate dummy1 = \true;
*/

/*@
predicate dummy2 = \true;
*/


int foo197(int n) {

		int *arr = (int *)malloc(sizeof(int) * (n + 1));
int arr_len = n + 1;
		arr[0] = 1;
		
            /*@
          loop invariant arr[0] == 1;
          loop assigns arr[0 .. n];
            */
            for (int c = 1; c <= n; c++) {
			arr[c] = 0;
			
            /* >>> LOOP INVARIANT TO FILL <<< */
            /*@
              loop invariant 0 <= k <= c;
              loop invariant arr[0] == 1;
              loop invariant \forall integer i; 0 <= i < c ==> arr[i] >= 0;
              loop assigns k, arr[c];
              loop variant c - k;
            */
            for (int k = 0; k < c; k++) {
				arr[c] += arr[k]
						* arr[c - k - 1];
			}
            
		}
            
		return arr[n];
}
