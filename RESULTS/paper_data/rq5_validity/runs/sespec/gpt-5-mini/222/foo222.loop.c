
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
*/

int foo222(int * arr, int arr_len, int n) {

    int result = 0;
    int offset = arr_len;
    
    /*@
      loop invariant 0 <= index && index <= \at(arr_len,Pre);
      loop invariant 0 <= result;
      loop invariant offset == \at(arr_len,Pre);
      loop invariant n == \at(n,Pre);
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant arr == \at(arr,Pre);
      loop invariant \forall integer k; 0 <= k < \at(arr_len,Pre) ==> 0 <= arr[k] <= 100;
      loop assigns index, result;
    */
    for (int index = 0; index < offset; index++) {
        
        /*@
          loop invariant 0 <= c && c <= offset;
          loop invariant 0 <= index && index < offset;
          loop invariant 0 <= result;
          loop assigns result;
        */
        for (int c = index + 1; c < offset; c++) {
            if ((arr[index] ^ arr[c]) % 2 == 1) {
                result++;
            }
        }
        
    }
    return result;
}
