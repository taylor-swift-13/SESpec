
/*@ predicate sorted_array(int *arr, integer n) =
      \forall integer i, j; 0 <= i <= j < n ==> arr[i] <= arr[j];
*/

/*@ 
  assigns arr[0 .. arr_len - 1], low, high, result;
  ensures \result == -1 || (0 <= \result < n);
  ensures (\result != -1) ==> arr[\result] == x;
  ensures (\result != -1) ==> \forall integer i; 0 <= i < \result ==> arr[i] != x;
  ensures (\result == -1) ==> \forall integer i; 0 <= i < n ==> arr[i] != x;
*/
int foo96(int * arr, int arr_len, int x, int n) {

        int low = 0;
        int high = n - 1;
        int result = -1;
        
            
        /*@
          loop invariant (0 <= \at(n,Pre) - 1) ==> (((result == -1)&&(high == \at(n,Pre) - 1)&&(low == 0)&&(n == \at(n,Pre))&&(x == \at(x,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (0 <= low <= \at(n,Pre)));
          loop invariant (0 <= \at(n,Pre) - 1) ==> (((result == -1)&&(high == \at(n,Pre) - 1)&&(low == 0)&&(n == \at(n,Pre))&&(x == \at(x,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (-1 <= high < \at(n,Pre)));
          loop invariant (0 <= \at(n,Pre) - 1) ==> (((result == -1)&&(high == \at(n,Pre) - 1)&&(low == 0)&&(n == \at(n,Pre))&&(x == \at(x,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (result == -1 || (0 <= result < \at(n,Pre))));
          loop invariant (!(0 <= \at(n,Pre) - 1)) ==> ((result == -1)&&(high == \at(n,Pre) - 1)&&(low == 0)&&(n == \at(n,Pre))&&(x == \at(x,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant n == \at(n,Pre);
          loop invariant x == \at(x,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \valid_read(arr + (0 .. n - 1));
          loop invariant sorted_array(arr, n);
          loop assigns mid, result, high, low;
            */
            while (low <= high) {
            int mid = (low + high) / 2;
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
