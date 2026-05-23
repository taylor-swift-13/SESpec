
/*@
  logic integer fib(integer n) =
    n <= 0 ? 2 :
    n == 1 ? 1 :
    fib(n - 1) + fib(n - 2);
*/

int foo297(int seed) {

		int *result = (int *)malloc(sizeof(int) * (seed + 1));
int result_len = seed + 1;
		result[0] = 2;
		result[1] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (l <= seed) ==> (l >= 2 && result[l - 1] == fib(l - 1) && result[l - 2] == fib(l - 2));
          loop assigns l, result[0..seed];
            */
            for (int l = 2; l <= seed; l++) {
			result[l] = result[l - 1]
					+ result[l - 2];
		}
            
		return result[seed];
}
