
/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  predicate sorted_segment(int* a, integer lo, integer hi) =
    \forall integer k1, k2; lo <= k1 <= k2 < hi ==> a[k1] <= a[k2];
*/

/*@
  assigns i, j, result;
  ensures result == -1 || (0 <= result < n);
  ensures result == -1 || arr[result] == x;
  ensures \forall integer k; 0 <= k < n ==> (arr[k] == x ==> (result == -1 || arr[result] == x));
*/
int foo95(int * arr, int arr_len, int x, int n) {

        int i = 0;
        int j = n - 1;
        int result = -1;

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 <= \at(n,Pre) - 1) ==> (((result == -1)&&(j == \at(n,Pre) - 1)&&(i == 0)&&(n == \at(n,Pre))&&(x == \at(x,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (0 <= i <= j + 1));
          loop invariant (0 <= \at(n,Pre) - 1) ==> (((result == -1)&&(j == \at(n,Pre) - 1)&&(i == 0)&&(n == \at(n,Pre))&&(x == \at(x,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (0 <= j < \at(n,Pre)));
          loop invariant (0 <= \at(n,Pre) - 1) ==> (((result == -1)&&(j == \at(n,Pre) - 1)&&(i == 0)&&(n == \at(n,Pre))&&(x == \at(x,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (result == -1 || (0 <= result < \at(n,Pre))));
          loop invariant (!(0 <= \at(n,Pre) - 1)) ==> ((result == -1)&&(j == \at(n,Pre) - 1)&&(i == 0)&&(n == \at(n,Pre))&&(x == \at(x,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant n == \at(n,Pre);
          loop invariant x == \at(x,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant 0 <= i <= arr_len;
          loop invariant -1 <= j < arr_len;
          loop invariant result == -1 || (0 <= result < arr_len);
          loop invariant \forall integer k; 0 <= k < i ==> arr[k] < x;
          loop invariant \forall integer k; j < k < n ==> arr[k] > x;
          loop invariant result != -1 ==> arr[result] == x;
          loop assigns mid, result, i, j;
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
