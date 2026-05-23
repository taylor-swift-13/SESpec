
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);

  logic integer sum(int* array, integer begin, integer end) =
    end <= begin ? 0 : sum(array, begin, end - 1) + array[end - 1];
*/

/*@
  requires \valid(arr1 + (0..arr1_len-1));
  requires \valid(arr + (0..arr_len-1));
  requires arr1_len > 0 && arr1_len < 100;
  requires arr_len > 0 && arr_len < 100;
  requires c >= 0;
  requires Array >= 0;
  requires n >= 0;
  assigns \nothing;
*/
int foo22(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int c) {

    int result = 0;
    int tmp = 0;

    /*@
      loop invariant 0 <= count <= c;
      loop invariant 0 <= result && result <= Array;
      loop invariant 0 <= tmp && tmp <= n + count;
      loop invariant (count < \at(c,Pre)) ==> (result >= 0 && result <= Array);
      loop invariant (count < \at(c,Pre)) ==> (tmp >= 0 && tmp <= n + count);
      loop invariant (!(count < \at(c,Pre))) ==> ((tmp == 0)&&(result == 0)&&(c == \at(c,Pre))&&(n == \at(n,Pre))&&(Array == \at(Array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))&&(arr1_len == \at(arr1_len,Pre))&&(arr1 == \at(arr1,Pre)));
      loop invariant c == \at(c,Pre);
      loop invariant n == \at(n,Pre);
      loop invariant Array == \at(Array,Pre);
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant arr == \at(arr,Pre);
      loop invariant arr1_len == \at(arr1_len,Pre);
      loop invariant arr1 == \at(arr1,Pre);
      loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
      loop invariant \forall integer k; 0 <= k < arr1_len ==> arr1[k] == \at(arr1[k], Pre);
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
