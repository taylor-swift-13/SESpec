
/*@
  requires p >= 1;
*/

int foo294(int p) {

		int *arr = (int *)malloc(sizeof(int) * (p + 1));
int arr_len = p + 1;
		arr[0] = 0;
		arr[1] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant p >= 1;
          loop invariant 2 <= count <= p + 1;
          loop invariant arr[0] == 0 && arr[1] == 1;
          loop invariant \forall integer i; 2 <= i < count ==> arr[i] == (2 * arr[i - 1] + arr[i - 2]) % 1000000000;
          loop assigns count, arr[2..p];
            */
            for (int count = 2; count <= p; count++) {
			arr[count] = (2 * arr[count - 1]
					+ arr[count - 2]) % 1000000000;
		}
            
		return arr[p];
}
