
/*@
  logic integer pairs_from_c{L}(int *a, integer c, integer j, integer off) =
    j >= off ? 0
             : (((a[c] ^ a[j]) % 2 == 1) ? 1 : 0) + pairs_from_c(a, c, j+1, off);
*/

/*@
  logic integer pairs_range{L}(int *a, integer lo, integer hi, integer off) =
    lo >= hi ? 0
             : pairs_range(a, lo, hi - 1, off) + pairs_from_c(a, hi - 1, hi, off);
*/

/*@
  requires arr_len >= 0;
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;   
  ensures \result >= 0;
  ensures \forall integer k; 0 <= k < arr_len ==> arr[k] == \old(arr[k]);
*/
int foo221(int * arr, int arr_len, int n) {

    int found = 0;
    int offset = arr_len;

    /*@
      loop invariant offset == \at(arr_len,Pre);
      loop invariant found >= 0;
      loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre);
      loop assigns c, found;
    */
    for (int c = 0; c < offset; c++) {

        /*@
          loop invariant found >= 0;
          loop invariant \forall integer i; 0 <= i < c ==> 0 <= arr[i] <= 100;
          loop assigns index, found;
        */
        for (int index = c + 1; index < offset; index++) {
            if ((arr[c] ^ arr[index]) % 2 == 1) {
                found++;
            }
        }
    }

    return found;
}
