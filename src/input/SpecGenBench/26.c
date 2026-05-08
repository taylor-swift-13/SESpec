#include <stdlib.h>

int foo26(int n);

int foo26(int n) {

		if(n < 0) return -1;
		else if(n == 0) return 0;

		int *fib = (int *)malloc(sizeof(int) * (n + 1));
int fib_len = n + 1;
		fib[0] = 0;
		fib[1] = 1;
		int index = 2;

		while (index < fib_len) {
			fib[index] = fib[index - 2] + fib[index - 1];
			index++;
		}

		return fib[n];
}
