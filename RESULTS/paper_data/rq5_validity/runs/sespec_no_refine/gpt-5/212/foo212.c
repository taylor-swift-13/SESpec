
/*@
  // Helper to express "all elements in a range are strictly less than a value".
  logic boolean all_lt(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? \true
             : all_lt(a, lo, hi - 1, v) && (a[hi - 1] < v);

  // Helper to express "all elements in a range are strictly greater than a value".
  logic boolean all_gt(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? \true
             : all_gt(a, lo, hi - 1, v) && (a[hi - 1] > v);
*/

/*@
  requires \at(arr1_len,Pre) > 0 && \at(arr1_len,Pre) < 100 && \at(arr2_len,Pre) > 0 && \at(arr2_len,Pre) < 100;
  assigns \nothing;
  ensures arr1 == \old(arr1) && arr2 == \old(arr2) && arr1_len == \old(arr1_len) && arr2_len == \old(arr2_len) && n == \old(n);
  ensures \forall integer k; 0 <= k < arr1_len ==> arr1[k] == \old(arr1[k]);
  ensures \forall integer k; 0 <= k < arr2_len ==> arr2[k] == \old(arr2[k]);
  ensures \result == \result;
*/
int foo212(int * arr1, int arr1_len, int * arr2, int arr2_len, int n) {

        int i = 0;
        int j = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 < \at(arr1_len,Pre) && 0 < \at(arr2_len,Pre)) ==> (0 <= i <= arr1_len) ;
          loop invariant (0 < \at(arr1_len,Pre) && 0 < \at(arr2_len,Pre)) ==> (0 <= j <= arr2_len) ;
          loop invariant (!(0 < \at(arr1_len,Pre) && 0 < \at(arr2_len,Pre))) ==> ((j == 0)&&(i == 0)&&(n == \at(n,Pre))&&(arr2_len == \at(arr2_len,Pre))&&(arr2 == \at(arr2,Pre))&&(arr1_len == \at(arr1_len,Pre))&&(arr1 == \at(arr1,Pre)));
          loop invariant n == \at(n,Pre);
          loop invariant arr2_len == \at(arr2_len,Pre);
          loop invariant arr2 == \at(arr2,Pre);
          loop invariant arr1_len == \at(arr1_len,Pre);
          loop invariant arr1 == \at(arr1,Pre);
          loop invariant \forall integer k; 0 <= k < arr2_len ==> arr2[k] == \at(arr2[k], Pre) ;
          loop invariant \forall integer k; 0 <= k < arr1_len ==> arr1[k] == \at(arr1[k], Pre) ;
          loop assigns i, j;
            */
            while (i < arr1_len && j < arr2_len) {
            if (arr1[i] < arr2[j]) {
                i++;
            } else if (arr1[i] > arr2[j]) {
                j++;
            } else {
                i++;
                j++;
            }
        }
            
        return i < arr1_len ? i : j;
}
