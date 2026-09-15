
/*@
  logic integer fib_like(int *result, integer c) =
    c <= 0 ? 0 :
    c == 1 ? 2 :
    c == 2 ? 1 :
    fib_like(result, c - 1) + fib_like(result, c - 2);
*/

int foo296(int seed) {

		int *result = (int *)malloc(sizeof(int) * (seed + 1));
int result_len = seed + 1;
		result[0] = 2;
		result[1] = 1;
		
            
        /*@
          loop invariant \forall integer i; 2 <= i < c ==> result[i] == result[i - 1] + result[i - 2];
          loop assigns c, result[0..seed];
            */
            for (int c = 2; c <= seed; c++) {
			result[c] = result[c - 1]
					+ result[c - 2];
		}
            
		return result[seed];
}
