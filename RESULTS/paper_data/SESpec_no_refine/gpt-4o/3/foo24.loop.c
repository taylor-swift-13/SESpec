
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
  ensures \result == -1 || (\result == arr1[\at(result, Pre)] || \result == arr[\at(tmp, Pre)]);
*/
int foo24(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int p) {

    int result = 0;
    int tmp = 0;

    /*@
      loop invariant 0 <= count <= p;
      loop invariant 0 <= result <= arr1_len;
      loop invariant 0 <= tmp <= arr_len;
      loop invariant (count < \at(p,Pre)) ==> (result < Array);
      loop invariant (count < \at(p,Pre)) ==> (tmp >= n || arr1[result] <= arr[tmp]);
      loop invariant (!(count < \at(p,Pre))) ==> ((tmp == 0)&&(result == 0)&&(p == \at(p,Pre))&&(n == \at(n,Pre))&&(Array == \at(Array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))&&(arr1_len == \at(arr1_len,Pre))&&(arr1 == \at(arr1,Pre)));
      loop invariant p == \at(p,Pre);
      loop invariant n == \at(n,Pre);
      loop invariant Array == \at(Array,Pre);
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant arr == \at(arr,Pre);
      loop invariant arr1_len == \at(arr1_len,Pre);
      loop invariant arr1 == \at(arr1,Pre);
      loop invariant \forall integer k; 0 <= k < arr1_len ==> arr1[k] == \at(arr1[k], Pre);
      loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
      loop assigns count, result, tmp;
    */
    for (int count = 0; count < p; count++) {
        if (result < Array
                && (tmp >= n || arr1[result] <= arr[tmp])) {
            if (count == p - 1) {
                return arr1[result];
            }
            result++;
        } else {
            if (count == p - 1) {
                return arr[tmp];
            }
            tmp++;
        }
    }

    return -1;
}
