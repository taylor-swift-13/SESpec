
#include <stdlib.h>

/*@ logic integer fib2_like(integer n) =
      n <= 0 ? 2 :
      n == 1 ? 1 :
      fib2_like(n-1) + fib2_like(n-2);
*/
/*@
  assigns \nothing;
  ensures num <= 0 ==> \result == 2;
  ensures num == 1 ==> \result == 1;
  ensures num >= 2 ==> \result == fib2_like(num);
*/
int foo295(int num) {

		int *result = (int *)malloc(sizeof(int) * (num + 1));
int result_len = num + 1;
		result[0] = 2;
		result[1] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 2 <= l <= num + 1;
          loop invariant \valid(result + (0 .. num));
          loop invariant result_len == num + 1;
          loop invariant result[0] == 2;
          loop invariant num >= 1 ==> result[1] == 1;
          loop invariant \forall integer k; 2 <= k < l ==> result[k] == result[k-1] + result[k-2];
          loop assigns l, result[..];
            */
            for (int l = 2; l <= num; l++) {
			result[l] = result[l - 1]
					+ result[l - 2];
		}
            
		return result[num];
}
