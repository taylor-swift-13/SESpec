#include <stdlib.h>

int foo239(int num);

int foo239(int num) {

		int *arr = (int *)malloc(sizeof(int) * (num + 1));
int arr_len = num + 1;
		arr[0] = 0;
		for (int index = 0; index <= num - 1; index++) {
			arr[index + 1] = arr[index] + 8 * index + 1;
		}
		return arr[num];
}
