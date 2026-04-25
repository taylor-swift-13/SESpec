#include <stdlib.h>

int foo146(int dim, int w);

int foo146(int dim, int w) {

		int count = 1000000007;
		int *div = (int *)malloc(sizeof(int) * (dim + 1));
int div_len = dim + 1;
		div[0] = 1;
		div[1] = w;
		div[2] = w * w;
		for (int d = 3; d <= dim; d++) {
			div[d] = ((w - 1)
					* (div[d - 1] + div[d - 2])) % count;
		}
		return div[dim];
}
