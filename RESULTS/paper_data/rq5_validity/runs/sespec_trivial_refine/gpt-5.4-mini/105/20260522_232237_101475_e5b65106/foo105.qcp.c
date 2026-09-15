#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo105(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

		if(n < 0) return -1;
		else if(n == 0) return 0;

		int *fib = (int *)malloc(sizeof(int) * (n + 1));
int fib_len = n + 1;
		fib[0] = 0;
		fib[1] = 1;
		int index = 2;

	
 	/*@ Inv
    (2 <= index && index <= fib_len) &&
    (fib_len == n + 1) &&
    (n >= 1)
    */
while (index < fib_len) {
			fib[index] = fib[index - 2] + fib[index - 1];
			index++;
		}

		return fib[n];
}