
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

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns start, end, mid;
  ensures \result == -1 || (\result >= 0 && \result < arr_len && arr[\result] == \result);
  ensures \result == -1 ==> \forall integer i; 0 <= i < arr_len ==> arr[i] != i;
  ensures \result >= 0 ==> arr[\result] == \result;
*/
int foo130(int * arr, int arr_len, int n) {

        int start = 0;
        int end = n - 1;
        
        /*@
          loop invariant 0 <= start <= end + 1 <= arr_len;
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop assigns start, end, mid;
          loop variant end - start + 1;
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
