#include <stddef.h>

int sumEvenAndEvenIndex(int * arr, int arr_len, int n);

/*@ 
  requires arr_len >= 0;
  requires n >= 0;
  requires n <= arr_len;
  requires \valid_read(arr + (0..n-1));
  assigns \nothing;
  ensures \result == \sum(i, 0, n-1, ((i % 2 == 0 && arr[i] % 2 == 0) ? arr[i] : 0));
*/
int sumEvenAndEvenIndex(int * arr, int arr_len, int n) {

        int count = 0;
        /*@
          loop invariant 0 <= i <= n;
          loop invariant count == \sum(k, 0, i-1, ((k % 2 == 0 && arr[k] % 2 == 0) ? arr[k] : 0));
          loop assigns i, count;
          loop variant n - i;
        */
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (arr[i] % 2 == 0) {
                    count += arr[i];
                }
            }
        }
        return count;
}
