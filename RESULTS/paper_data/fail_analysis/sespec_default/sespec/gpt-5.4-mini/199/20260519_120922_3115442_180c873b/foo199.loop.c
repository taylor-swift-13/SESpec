```c
        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        

/*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        


int foo199(int number) {

		int *arr = (int *)malloc(sizeof(int) * (number + 1));
int arr_len = number + 1;
		arr[0] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= c <= number + 1;
          loop invariant arr[0] == 1;
          loop invariant \forall integer i; 0 <= i < c ==> arr[i] >= 0;
          loop assigns c, arr[..];
            */
            for (int c = 1; c <= number; c++) {
			arr[c] = 0;
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= n <= c;
          loop invariant 0 <= c <= number;
          loop invariant arr[0] == 1;
          loop invariant \forall integer i; 0 <= i < c ==> arr[i] >= 0;
          loop assigns n, arr[c];
          loop variant c - n;
            */
            for (int n = 0; n < c; n++) {
				arr[c] += arr[n]
						* arr[c - n - 1];
			}
            
		}
            
		return arr[number];
}`