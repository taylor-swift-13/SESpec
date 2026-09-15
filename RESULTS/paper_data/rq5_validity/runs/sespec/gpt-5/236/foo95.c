
/*@
  requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
  requires \valid_read(arr + (0..\at(arr_len,Pre)-1));
  requires 0 <= \at(n,Pre) <= \at(arr_len,Pre);
  requires \forall integer k1,k2; 0 <= k1 <= k2 < \at(arr_len,Pre) ==> \at(arr[k1],Pre) <= \at(arr[k2],Pre);
  assigns \nothing;
  ensures (\result == -1) || (0 <= \result && \result < n && arr[\result] == x);
  ensures \result == (\result);
*/
int foo95(int * arr, int arr_len, int x, int n) {

        int i = 0;
        int j = n - 1;
        int result = -1;

        /*@
          loop invariant 0 <= i && i <= \at(n,Pre);
          loop invariant -1 <= j && j < \at(n,Pre);
          loop invariant (i <= j) ==> (0 <= i && j < \at(n,Pre));
          loop invariant (0 <= i && j < \at(n,Pre)) || (i == j + 1);
          loop invariant (result == -1) || (0 <= result && result < \at(n,Pre) && arr[result] == x);
          loop invariant (0 <= \at(n,Pre) - 1) ==> (((result == -1) && (j == \at(n,Pre) - 1) && (i == 0) && (n == \at(n,Pre)) && (x == \at(x,Pre)) && (arr_len == \at(arr_len,Pre)) && (arr == \at(arr,Pre))) || (0 <= i && i <= \at(n,Pre)));
          loop invariant (0 <= \at(n,Pre) - 1) ==> (((result == -1) && (j == \at(n,Pre) - 1) && (i == 0) && (n == \at(n,Pre)) && (x == \at(x,Pre)) && (arr_len == \at(arr_len,Pre)) && (arr == \at(arr,Pre))) || (-1 <= j && j < \at(n,Pre)));
          loop invariant (0 <= \at(n,Pre) - 1) ==> (((result == -1) && (j == \at(n,Pre) - 1) && (i == 0) && (n == \at(n,Pre)) && (x == \at(x,Pre)) && (arr_len == \at(arr_len,Pre)) && (arr == \at(arr,Pre))) || ((result == -1) || (0 <= result && result < \at(n,Pre) && arr[result] == x)));
          loop invariant (!(0 <= \at(n,Pre) - 1)) ==> ((result == -1) && (j == \at(n,Pre) - 1) && (i == 0) && (n == \at(n,Pre)) && (x == \at(x,Pre)) && (arr_len == \at(arr_len,Pre)) && (arr == \at(arr,Pre)));
          loop invariant n == \at(n,Pre);
          loop invariant x == \at(x,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \valid_read(arr + (0..\at(arr_len,Pre)-1));
          loop assigns result, i, j;
        */
        while (i <= j) {
            int mid = (i + j) / 2;
            if (arr[mid] == x) {
                result = mid;
                i = mid + 1;
            } else if (arr[mid] < x) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }

        return result;
}
