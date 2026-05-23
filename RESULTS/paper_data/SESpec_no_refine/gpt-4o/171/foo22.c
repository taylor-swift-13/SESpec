
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);

  logic integer sum(int* array, integer begin, integer end) =
    end <= begin ? 0 : sum(array, begin, end - 1) + array[end - 1];

  logic integer max(int* array, integer begin, integer end) =
    end <= begin ? array[begin] : (array[end - 1] > max(array, begin, end - 1) ? array[end - 1] : max(array, begin, end - 1));
*/

/*@
  requires \at(arr1_len,Pre) > 0 && \at(arr1_len,Pre) < 100;
  requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
  requires \valid(arr1 + (0 .. arr1_len - 1));
  requires \valid(arr + (0 .. arr_len - 1));
  assigns \nothing;
*/
int foo22(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int c) {

    int result = 0;
    int tmp = 0;

    /*@
      loop invariant c == \at(c,Pre);
      loop invariant n == \at(n,Pre);
      loop invariant Array == \at(Array,Pre);
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant arr == \at(arr,Pre);
      loop invariant arr1_len == \at(arr1_len,Pre);
      loop invariant arr1 == \at(arr1,Pre);
      loop invariant \forall integer i; 0 <= i < arr1_len ==> arr1[i] == \at(arr1[i],Pre);
      loop invariant \forall integer i; 0 <= i < arr_len ==> arr[i] == \at(arr[i],Pre);
      loop assigns count, result, tmp;
    */
    for (int count = 0; count < c; count++) {
        if (result < Array
                && (tmp >= n || arr1[result] <= arr[tmp])) {
            if (count == c - 1) {
                return arr1[result];
            }
            result++;
        } else {
            if (count == c - 1) {
                return arr[tmp];
            }
            tmp++;
        }
    }

    return -1;
}
