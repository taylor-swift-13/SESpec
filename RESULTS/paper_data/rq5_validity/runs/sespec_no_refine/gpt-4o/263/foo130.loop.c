
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  logic integer sum{L}(int* array, integer begin, integer end) =
    end <= begin ? 0 : sum(array, begin, end - 1) + array[end - 1];
*/

/*@
  logic integer cntpos(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : cntpos(a, lo, hi - 1) + (a[hi - 1] > 0 ? 1 : 0);
*/

/*@
  logic integer max(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : (a[hi - 1] > max(a, lo, hi - 1) ? a[hi - 1] : max(a, lo, hi - 1));
*/

/*@
  logic integer min(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : (a[hi - 1] < min(a, lo, hi - 1) ? a[hi - 1] : min(a, lo, hi - 1));
*/

int foo130(int * arr, int arr_len, int n) {

        int start = 0;
        int end = n - 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 <= \at(n,Pre) - 1) ==> (((end == \at(n,Pre) - 1)&&(start == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (start >=0));
          loop invariant (0 <= \at(n,Pre) - 1) ==> (((end == \at(n,Pre) - 1)&&(start == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (end<=arr_len));
          loop invariant (!(0 <= \at(n,Pre) - 1)) ==> ((end == \at(n,Pre) - 1)&&(start == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop assigns mid, start, end;
            */
            while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == mid) {
                return mid;
            } else if (arr[mid] < mid) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
            
        return -1;
}
