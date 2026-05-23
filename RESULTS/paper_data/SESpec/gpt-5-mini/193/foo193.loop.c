
/*@
  logic integer arr_spec(integer i) =
    i == 0 ? 1
    : i == 1 ? 0
    : arr_spec(i-2) + 2 * C_spec(i-1);

  logic integer C_spec(integer i) =
    i == 0 ? 0
    : i == 1 ? 1
    : arr_spec(i-1) + C_spec(i-2);
*/

/*@
  requires count >= 0;
*/
int foo193(int count) {

		int *arr = (int *)malloc(sizeof(int) * (count + 1));
int arr_len = count + 1;
		int *C = (int *)malloc(sizeof(int) * (count + 1));
int C_len = count + 1;
		arr[0] = 1;
		arr[1] = 0;
		C[0] = 0;
		C[1] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 2 <= w <= count + 1;
          loop invariant \valid(arr + (0 .. count));
          loop invariant \valid(C + (0 .. count));
          loop invariant \forall integer k; 0 <= k < w ==> arr[k] == arr_spec(k) && C[k] == C_spec(k);
          loop assigns w, arr[0..count], C[0..count];
            */
            for (int w = 2; w <= count; w++) {
			arr[w] = arr[w - 2]
					+ 2 * C[w - 1];
			C[w] = arr[w - 1] + C[w - 2];
		}
            
		return arr[count];
}
