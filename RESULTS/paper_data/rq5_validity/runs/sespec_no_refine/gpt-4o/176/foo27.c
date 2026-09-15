
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
  logic integer max(int* array, integer begin, integer end) =
    end <= begin ? 0 : max(array, begin, end - 1) > array[end - 1] ? max(array, begin, end - 1) : array[end - 1];
*/

/*@
  logic integer min(int* array, integer begin, integer end) =
    end <= begin ? 0 : min(array, begin, end - 1) < array[end - 1] ? min(array, begin, end - 1) : array[end - 1];
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns found, hi, end;
  ensures \result == -1 ==> \forall integer i; 0 <= i < arr_len ==> arr[i] != array;
  ensures \result >= 0 ==> arr[\result] == array && (\result == arr_len - 1 || arr[\result + 1] != array);
*/
int foo27(int * arr, int arr_len, int array) {

    int found = 0;
    int hi = arr_len - 1;
    int end = 0;

    /*@
      loop invariant 0 <= found <= arr_len;
      loop invariant -1 <= hi < arr_len;
      loop invariant 0 <= end < arr_len;
      loop invariant \forall integer i; 0 <= i < found ==> arr[i] < array;
      loop invariant \forall integer i; hi < i < arr_len ==> arr[i] > array;
      loop assigns found, hi, end;
      loop variant hi - found + 1;
    */
    while (found <= hi) {
        end = (found + hi) / 2;
        if (arr[end] == array) {
            if (end == arr_len - 1 || arr[end + 1] != array) {
                return end;
            } else {
                found = end + 1;
            }
        } else if (arr[end] < array) {
            found = end + 1;
        } else {
            hi = end - 1;
        }
    }

    return -1;
}
