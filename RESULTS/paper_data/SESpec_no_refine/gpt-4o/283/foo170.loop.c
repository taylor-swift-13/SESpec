
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  logic integer sum(int* array, integer begin, integer end) =
    end <= begin ? 0 : sum(array, begin, end - 1) + array[end - 1];
*/

int foo170(int * arr, int arr_len, int n) {

        int i = 0;
        
        /*@
          loop invariant (0 < \at(n,Pre) - 1) ==> (i == 0) ;
          loop invariant (!(0 < \at(n,Pre) - 1)) ==> ((i == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant PLACE_HOLDER_ARRAY_arr ;
          loop assigns i;
            */
            while (i < n - 1) {
            if (arr[i] == arr[i + 1]) {
                i += 2;
            } else {
                return arr[i];
            }
        }
            
        return arr[n - 1];
}
