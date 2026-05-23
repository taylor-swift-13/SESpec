
#include <stdlib.h>

/*@
  logic integer fib_at(integer k) =
    k == 0 ? 0
    : k == 1 ? 1
    : fib_at(k-1) + fib_at(k-2);
*/

/*@
  requires n >= 0;
  assigns \nothing;
*/
int foo105(int n) {

		if(n < 0) return -1;
		else if(n == 0) return 0;

		int *fib = (int *)malloc(sizeof(int) * (n + 1));
int fib_len = n + 1;
		fib[0] = 0;
		fib[1] = 1;
		int index = 2;

		
            
        /*@
          loop invariant 0 <= index <= fib_len;
          loop assigns fib[0..fib_len-1], index;
        */
            while (index < fib_len) {
			fib[index] = fib[index - 2] + fib[index - 1];
			index++;
		}
            

		return fib[n];
}
