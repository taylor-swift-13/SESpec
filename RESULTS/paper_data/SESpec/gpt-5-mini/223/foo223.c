
/*@
predicate valid_arr(int *arr, integer len) = \valid(arr + (0 .. len-1));
*/



/*@
   requires \valid(arr + (0 .. arr_len-1));
   requires 0 <= arr_len;
   requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
   assigns \nothing;
    */
int foo223(int * arr, int arr_len, int n) {

    int result = 0;
    int offset = arr_len;

    /*@
      loop invariant arr == \at(arr, Pre);
      loop invariant valid_arr(arr, arr_len);
      loop invariant \forall integer k; 0 <= k < arr_len ==> 0 <= arr[k] <= 100;
      loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
      loop assigns result, offset;
    */
    for (int c = 0; c < offset; c++) {

        /*@
          loop invariant valid_arr(arr, arr_len);
          loop assigns result, index;
        */
        for (int index = c + 1; index < offset; index++) {
            if ((arr[c] ^ arr[index]) % 2 == 1) {
                result++;
            }
        }

    }

    return result;
}
