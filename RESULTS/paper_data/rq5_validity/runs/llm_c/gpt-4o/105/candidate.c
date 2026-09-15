#include <stdlib.h>

/*@
    requires n >= 0;
    ensures \result == -1 ==> n < 0;
    ensures \result == 0 ==> n == 0;
    ensures n > 0 ==> \result == \sum(0, n, \lambda integer i; (i == 0 ? 0 : (i == 1 ? 1 : \sum(0, i-2, \lambda integer j; (j == 0 ? 0 : (j == 1 ? 1 : \sum(0, j-2, \lambda integer k; (k == 0 ? 0 : (k == 1 ? 1 : ...))))))))));
    assigns \nothing;
*/
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
		    loop invariant \forall integer i; 0 <= i < index ==> fib[i] == (i == 0 ? 0 : (i == 1 ? 1 : fib[i-2] + fib[i-1]));
		    loop assigns index, fib[2..fib_len-1];
		    loop variant fib_len - index;
		*/
		while (index < fib_len) {
			fib[index] = fib[index - 2] + fib[index - 1];
			index++;
		}

		return fib[n];
}
