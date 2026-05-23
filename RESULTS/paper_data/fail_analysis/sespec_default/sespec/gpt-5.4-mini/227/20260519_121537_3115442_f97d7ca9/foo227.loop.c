
int foo227(int b) {

		int result = 0;
		int *arr = (int *)malloc(sizeof(int) * (b + 1));
int arr_len = b + 1;
		arr[0] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (!(d <= b)) ==> (\true);
          loop assigns d, arr[0 .. b];
            */
            for (int d = 1; d <= b; d++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop assigns d, arr[0 .. b];
              loop variant b - d + 1;
            */
            for (int c = 0; c < d; c++) {
				arr[d] = arr[d] + arr[c];
			}
            
		}
            
		return arr[b];
}
