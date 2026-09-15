#include <stdlib.h>

/*@
    requires n >= 0;
    assigns \nothing;
    ensures \result >= 0;
*/
int fibCompute(int n);

int fibCompute(int n) {
		if(n < 0) return -1;
		else if(n == 0) return 0;

		int *fib = (int *)malloc(sizeof(int) * (n + 1));
int fib_len = n + 1;
		fib[0] = 0;
		fib[1] = 1;
		int index = 2;

		/*@
		    loop invariant 2 <= index <= fib_len;
		    loop invariant fib[0] == 0;
		    loop invariant fib[1] == 1;
		    loop invariant \forall integer i; 2 <= i < index ==> fib[i] == fib[i-1] + fib[i-2];
		    loop assigns index, fib[2..fib_len-1];
		    loop variant fib_len - index;
		*/
		while (index < fib_len) {
			fib[index] = fib[index - 2] + fib[index - 1];
			index++;
		}

		return fib[n];
}
