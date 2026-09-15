#include <stddef.h>

int first(int * arr, int arr_len, int x, int n);

/*@ 
  requires arr_len >= 0;
  requires 0 <= n <= arr_len;
  requires \valid_read(arr + (0 .. arr_len-1));
  requires \forall integer i, j; 0 <= i <= j < n ==> arr[i] <= arr[j];
  assigns \nothing;
  ensures
    (\result == -1 ==> (\forall integer k; 0 <= k < n ==> arr[k] != x));
  ensures
    (\result != -1 ==> 0 <= \result < n &&
                       arr[\result] == x &&
                       (\result == 0 || arr[\result - 1] < x));
*/
int first(int * arr, int arr_len, int x, int n) {

        int low = 0;
        int high = n - 1;
        int result = -1;
        /*@
          loop invariant 0 <= low <= n;
          loop invariant -1 <= high < n;
          loop invariant result == -1 || (0 <= result < n && arr[result] == x);
          loop invariant \forall integer i; 0 <= i < low ==> arr[i] < x;
          loop invariant \forall integer i; high < i < n ==> arr[i] >= x;
          loop assigns low, high, result;
          loop variant high - low + 1;
        */
        while (low <= high) {
            int mid = (low + high) / 2;
            /*@ assert 0 <= mid < n; */
            if (arr[mid] == x) {
                result = mid;
                high = mid - 1;
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
}
