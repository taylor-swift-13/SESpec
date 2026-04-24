#include <stdlib.h>

int getPell(int p);

int getPell(int p) {

		int *arr = (int *)malloc(sizeof(int) * (p + 1));
int arr_len = p + 1;
		arr[0] = 0;
		arr[1] = 1;
		for (int count = 2; count <= p; count++) {
			arr[count] = (2 * arr[count - 1]
					+ arr[count - 2]) % 1000000000;
		}
		return arr[p];
}
