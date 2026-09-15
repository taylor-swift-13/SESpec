
/*@ 
  logic integer fib(integer n) =
    n == 0 ? 2
  : n == 1 ? 1
  : fib(n-1) + fib(n-2);
*/

#include <stdlib.h>

/*@
  requires num >= 1;
  ensures \result == \old(\result); // dummy to allow compilation of function spec area
*/
int foo295(int num) {

		int *result = (int *)malloc(sizeof(int) * (num + 1));
int result_len = num + 1;
		result[0] = 2;
		result[1] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 2 <= l;
          loop invariant l <= num + 1;
          loop invariant result_len == num + 1 && 0 <= num;
          loop invariant  (l <= num) ==> (result[l-1] == fib(l-1) && result[l-2] == fib(l-2));
          loop invariant  (!(l <= num)) ==> (result[num] == fib(num));
          loop assigns l, result[0 .. result_len - 1];
            */
            for (int l = 2; l <= num; l++) {
			result[l] = result[l - 1]
					+ result[l - 2];
		}
            
		return result[num];
}
