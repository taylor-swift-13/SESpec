#include <stddef.h>

/*@ 
  requires arr == \null || arr_len <= 0 || \valid_read(arr + (0 .. arr_len-1));
  assigns \nothing;

  behavior null_pointer:
    assumes arr == \null;
    ensures \result == -1;

  behavior nonnull_pointer:
    assumes arr != \null;
    ensures arr_len <= 1 ==> \result == 0;
    ensures arr_len > 1 ==> 0 <= \result <= (arr_len * (arr_len - 1)) / 2;
    ensures arr_len >= 0 ==>
      \result ==
        \sum(integer p, 0, arr_len-1,
             \sum(integer q, p+1, arr_len-1,
                  (((arr[p] ^ arr[q]) & 1) == 0) ? 1 : 0));

  complete behaviors;
  disjoint behaviors;
*/
int findEvenPair(int * arr, int arr_len, int n);

int findEvenPair(int * arr, int arr_len, int n) {

		if (arr == NULL) {
			return -1;
		}
		if (arr_len == 1) {
			return 0;
		}

		int evenPairCount = 0;
		/*@
		  loop invariant 0 <= i <= arr_len;
		  loop invariant arr_len >= 0 ==>
		    evenPairCount ==
		      \sum(integer p, 0, i-1,
		           \sum(integer q, p+1, arr_len-1,
		                (((arr[p] ^ arr[q]) & 1) == 0) ? 1 : 0));
		  loop assigns i, evenPairCount;
		  loop variant arr_len - i;
		*/
		for (int i = 0; i < arr_len; i++) {
			/*@
			  loop invariant i + 1 <= c <= arr_len;
			  loop invariant arr_len >= 0 ==>
			    evenPairCount ==
			      \sum(integer p, 0, i-1,
			           \sum(integer q, p+1, arr_len-1,
			                (((arr[p] ^ arr[q]) & 1) == 0) ? 1 : 0))
			      + \sum(integer j, i+1, c-1,
			             (((arr[i] ^ arr[j]) & 1) == 0) ? 1 : 0);
			  loop assigns c, evenPairCount;
			  loop variant arr_len - c;
			*/
			for (int c = i + 1; c < arr_len; c++) {
				int pair = arr[i];
				int odd = arr[c];
				int even = pair ^ odd;
				if ((even & 1) == 0) {
					evenPairCount++;
				}
			}
		}
		return evenPairCount;
}
