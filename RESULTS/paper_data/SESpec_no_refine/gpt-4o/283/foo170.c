
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  logic integer sum(int* array, integer begin, integer end) =
    end <= begin ? 0 : sum(array, begin, end - 1) + array[end - 1];
*/

/*@
  requires \valid(&arr[0..arr_len-1]);
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  requires n > 0;
  requires n <= arr_len;
  assigns i;
  ensures \result == (count_adjacent_unequal(arr, n) > 0 ? arr[\at(i,Post)] : arr[n - 1]);
  ensures i == n - 1 || (0 <= i < n - 1 && arr[i] != arr[i + 1]);
*/
int foo170(int * arr, int arr_len, int n) {

        int i = 0;
        
        /*@
          loop invariant 0 <= i <= n;
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < i ==> arr[k] == arr[k + 1];
          loop assigns i;
          loop variant n - i;
        */
        while (i < n - 1) {
            if (arr[i] == arr[i + 1]) {
                i += 2;
            } else {
                return arr[i];
            }
        }
            
        return arr[n - 1];
}
