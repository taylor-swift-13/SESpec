
/*@
  logic integer count_prefix{L}(int *a, integer len, integer k) =
    k <= 0 ? 0
    : (k <= len ? count_prefix(a, len, k-1) + 1 : count_prefix(a, len, len));
*/

/*@
  requires arr1_len >= 0;
  requires arr2_len >= 0;
  requires arr1_len == 0 || \valid_read(arr1 + (0 .. arr1_len - 1));
  requires arr2_len == 0 || \valid_read(arr2 + (0 .. arr2_len - 1));
*/
int foo212(int * arr1, int arr1_len, int * arr2, int arr2_len, int n) {

        int i = 0;
        int j = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= arr1_len;
          loop invariant 0 <= j <= arr2_len;
          loop invariant n == \at(n,Pre);
          loop invariant (0 < \at(arr1_len,Pre) && 0 < \at(arr2_len,Pre)) ==>
                         (\forall integer ii; 0 <= ii < i ==> arr1[ii] <= \at(arr1[ii],Pre));
          loop invariant (0 < \at(arr1_len,Pre) && 0 < \at(arr2_len,Pre)) ==>
                           (i == i && j == j);
          loop invariant (0 < \at(arr1_len,Pre) && 0 < \at(arr2_len,Pre)) ==> (0 <= i && 0 <= j);
          loop invariant (!(0 < \at(arr1_len,Pre) && 0 < \at(arr2_len,Pre))) ==> ((j == 0)&&(i == 0)&&(n == \at(n,Pre))&&(arr2_len == \at(arr2_len,Pre))&&(arr2 == \at(arr2,Pre))&&(arr1_len == \at(arr1_len,Pre))&&(arr1 == \at(arr1,Pre)));
          loop invariant n == \at(n,Pre);
          loop invariant arr2_len == \at(arr2_len,Pre);
          loop invariant arr2 == \at(arr2,Pre);
          loop invariant arr1_len == \at(arr1_len,Pre);
          loop invariant arr1 == \at(arr1,Pre);
          loop invariant \forall integer k; 0 <= k < arr1_len ==> arr1[k] == \at(arr1[k],Pre);
          loop invariant \forall integer k; 0 <= k < arr2_len ==> arr2[k] == \at(arr2[k],Pre);
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
