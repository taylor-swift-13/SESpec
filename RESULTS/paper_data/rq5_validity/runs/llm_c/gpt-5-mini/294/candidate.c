#include <stdlib.h>

int getPell(int p);

/*@ 
    logic integer Pell(integer n) =
        n == 0 ? 0 :
        n == 1 ? 1 :
        (2 * Pell(n-1) + Pell(n-2)) % 1000000000;

    requires p >= 1;
    assigns \nothing;
    ensures \result == Pell(p);
*/
int getPell(int p) {

		int *arr = (int *)malloc(sizeof(int) * (p + 1));
int arr_len = p + 1;
		arr[0] = 0;
		arr[1] = 1;
		/*@ 
		    loop invariant 2 <= count <= p + 1;
		    loop invariant \forall integer j; 0 <= j < count ==> arr[j] == Pell(j);
		    loop assigns count, arr[2..p];
		    loop variant p - count + 1;
		*/
		for (int count = 2; count <= p; count++) {
			arr[count] = (2 * arr[count - 1]
					+ arr[count - 2]) % 1000000000;
		}
		return arr[p];
}
