#include <stdlib.h>

int foo5(int * args, int args_len, int Array);

int foo5(int * args, int args_len, int Array) {

		int *mpis = (int *)malloc(sizeof(int) * (Array));
int mpis_len = Array;
		for (int array = 0; array < Array; array++) {
			mpis[array] = args[array];
		}
		for (int i = 1; i < Array; i++) {
			for (int p = 0; p < i; p++) {
				if (args[i] > args[p]
						&& mpis[i] < (mpis[p] * args[i])) {
					mpis[i] = mpis[p] * args[i];
				}
			}
		}
		int result = mpis[0];
		for (int i = 1; i < Array; i++) {
			if (mpis[i] > result) {
				result = mpis[i];
			}
		}
		return result;
}
