
/*@
  // No additional predicate or logic function is required for this program.
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;
  ensures \result == 
           \sum(0 <= c < arr_len, 
                \sum(c + 1 <= index < arr_len, 
                     ((arr[c] ^ arr[index]) % 2 == 1 ? 1 : 0)));
*/
int foo82(int * arr, int arr_len, int n) {

    int result = 0;
    int offset = arr_len;

    /*@
      loop invariant 0 <= c <= offset;
      loop invariant result >= 0;
      loop invariant offset == \at(arr_len, Pre);
      loop invariant n == \at(n, Pre);
      loop invariant arr_len == \at(arr_len, Pre);
      loop invariant arr == \at(arr, Pre);
      loop invariant result == 
           \sum(0 <= i < c, 
                \sum(i + 1 <= j < offset, 
                     ((arr[i] ^ arr[j]) % 2 == 1 ? 1 : 0)));
      loop assigns c, result;
    */
    for (int c = 0; c < offset; c++) {

        /*@
          loop invariant c + 1 <= index <= offset;
          loop invariant result >= 0;
          loop invariant result == 
               \sum(0 <= i < c, 
                    \sum(i + 1 <= j < offset, 
                         ((arr[i] ^ arr[j]) % 2 == 1 ? 1 : 0)))
               + \sum(c + 1 <= j < index, 
                      ((arr[c] ^ arr[j]) % 2 == 1 ? 1 : 0));
          loop invariant offset == \at(arr_len, Pre);
          loop invariant n == \at(n, Pre);
          loop invariant arr_len == \at(arr_len, Pre);
          loop invariant arr == \at(arr, Pre);
          loop assigns index, result;
        */
        for (int index = c + 1; index < offset; index++) {
            if ((arr[c] ^ arr[index]) % 2 == 1) {
                result++;
            }
        }
    }

    return result;
}
