
/*@
 logic integer imax(integer a, integer b) = a > b ? a : b;
*/

/*@
  requires arr_len > 0;
  requires \valid_read(arr + (0 .. arr_len - 1));
  assigns \nothing;
  ensures \true;
*/
int foo284(int * arr, int arr_len) {

    int result = 0;
    int min = arr[0];

    /*@
      loop invariant 1 <= i <= arr_len;
      loop assigns i, result, min;
      loop variant arr_len - i;
    */
    for (int i = 1; i < arr_len; i++) {
        if (arr[i] > min) {
            result = result > min ? result : min;
        } else {
            min = arr[i];
        }
    }

    return result;
}
