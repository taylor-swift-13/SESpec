
/*@
  logic integer count_odd(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : count_odd(a, lo, hi - 1) + (a[hi - 1] % 2 != 0 ? 1 : 0);
*/

/*@
  logic integer last_odd(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : (a[hi - 1] % 2 != 0 ? a[hi - 1] : last_odd(a, lo, hi - 1));
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires 0 <= arrSize <= arr_len; // Strengthened precondition to ensure arrSize is valid
  assigns \nothing;
  ensures \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
  ensures arrSize == \at(arrSize, Pre);
  ensures arr_len == \at(arr_len, Pre);
  ensures arr == \at(arr, Pre);
*/
int foo271(int * arr, int arr_len, int arrSize) {

    int result = 0;
    int count = 0;

    /*@
      loop invariant 0 <= i <= arrSize; // Strengthened invariant to ensure validity during loop execution
      loop invariant 0 <= count <= i;
      loop invariant count == count_odd(arr, 0, i);
      loop invariant (count % 2 != 0) ==> (result == last_odd(arr, 0, i));
      loop invariant \forall integer k; 0 <= k < i ==> arr[k] == \at(arr[k], Pre);
      loop invariant arrSize == \at(arrSize, Pre);
      loop invariant arr_len == \at(arr_len, Pre);
      loop invariant arr == \at(arr, Pre);
      loop assigns i, result, count;
    */
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 != 0) {
            count++;
            if (count % 2 != 0) {
                result = arr[i];
            }
        }
    }

    return result;
}
