
        /*@
        */
        

int foo297(int seed) {

		int *result = (int *)malloc(sizeof(int) * (seed + 1));
int result_len = seed + 1;
		result[0] = 2;
		result[1] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant result != \null;
          loop invariant 2 <= l;
          loop invariant seed < 2 || l <= seed + 1;
          loop invariant \forall integer i; 2 <= i < l ==> result[i] == result[i - 1] + result[i - 2];
          loop assigns l, result[2..seed];
            */
            for (int l = 2; l <= seed; l++) {
			result[l] = result[l - 1]
					+ result[l - 2];
		}
            
		return result[seed];
}
