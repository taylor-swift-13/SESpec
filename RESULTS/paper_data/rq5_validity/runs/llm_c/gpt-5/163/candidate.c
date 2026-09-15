#include <stddef.h>

int findEvenPair(int * arr, int arr_len, int n);

/*@
  behavior null:
    assumes arr == \null;
    assigns \nothing;
    ensures \result == -1;

  behavior short:
    assumes arr != \null && arr_len <= 1;
    assigns \nothing;
    ensures \result == 0;

  behavior normal:
    assumes arr != \null && arr_len >= 2;
    requires \valid_read(arr + (0 .. arr_len-1));
    assigns \nothing;
    ensures \result ==
      \numof integer i; 0 <= i < arr_len - 1;
        \numof integer j; i+1 <= j < arr_len &&
          (arr[i] % 2 == arr[j] % 2);
    ensures 0 <= \result <= (arr_len * (arr_len - 1)) / 2;

  complete behaviors;
  disjoint behaviors;
*/
int findEvenPair(int * arr, int arr_len, int n) {

		if (arr == NULL) {
			return -1;
		}
		if (arr_len == 1) {
			return 0;
		}

		int evenPairCount = 0;
		/*@
		  loop invariant i >= 0;
		  loop invariant arr_len >= 2 ==>
		    evenPairCount ==
		      \numof integer p; 0 <= p < i;
		        \numof integer q; p < q < arr_len &&
		          (arr[p] % 2 == arr[q] % 2);
		  loop variant arr_len - i;
		*/
		for (int i = 0; i < arr_len; i++) {
			/*@
			  loop invariant arr_len >= 2 ==> i+1 <= c <= arr_len;
			  loop invariant arr_len >= 2 ==>
			    evenPairCount ==
			      (\numof integer p; 0 <= p < i;
			         \numof integer q; p < q < arr_len &&
			           (arr[p] % 2 == arr[q] % 2))
			      + \numof integer q; i+1 <= q < c &&
			           (arr[i] % 2 == arr[q] % 2);
			  loop variant arr_len - c;
			*/
			for (int c = i + 1; c < arr_len; c++) {
				int odd = arr[i];
				int b = arr[c];
				int even = odd ^ b;
				if ((even & 1) == 0) {
					evenPairCount++;
				}
			}
		}
		return evenPairCount;
}
