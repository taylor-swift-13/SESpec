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
    (fib[0] == 0) &&
    (fib[1] == 1) &&
    (forall (k:Z), 2 <= k && k < index => fib[k] == fib[k-1] + fib[k-2]) &&
    (forall (k:Z), 0 <= k && k < index => fib[k] >= 0) &&
    (forall (k:Z), 1 <= k && k < index => fib[k] >= fib[k-1]) &&
    ((index < fib_len) => (fib[index - 2] >= 0 && fib[index - 1] >= 0)) &&
    ((!(index < fib_len)) => (index == fib_len))
    */
while (index < fib_len) {
        fib[index] = fib[index - 2] + fib[index - 1];
        index++;
    }

		return fib[n];
}