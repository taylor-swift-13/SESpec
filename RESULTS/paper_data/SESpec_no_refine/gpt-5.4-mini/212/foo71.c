
/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(&arr1[0] + (0..arr1_len-1));
  requires \forall integer i; 0 <= i < arr1_len ==> 0 <= arr1[i] <= 100;
  requires arr1_len > 0;
  requires arr1_len < 100;
  requires \valid(&arr2[0] + (0..arr2_len-1));
  requires \forall integer i; 0 <= i < arr2_len ==> 0 <= arr2[i] <= 100;
  requires arr2_len > 0;
  requires arr2_len < 100;
  assigns \nothing;
  ensures \result == (i < arr1_len ? i : j);
  ensures \result == (arr1_len < arr2_len ? arr1_len : arr2_len);
*/
int foo71(int * arr1, int arr1_len, int * arr2, int arr2_len, int n) {

        int i = 0;
        int j = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 < \at(arr1_len,Pre) && 0 < \at(arr2_len,Pre)) ==> (0 <= i <= arr1_len);
          loop invariant (0 < \at(arr1_len,Pre) && 0 < \at(arr2_len,Pre)) ==> (0 <= j <= arr2_len);
          loop invariant (0 < \at(arr1_len,Pre) && 0 < \at(arr2_len,Pre)) ==> (i + j <= arr1_len + arr2_len);
          loop invariant (0 < \at(arr1_len,Pre) && 0 < \at(arr2_len,Pre)) ==> (\forall integer k; 0 <= k < i ==> \forall integer l; 0 <= l < j ==> (arr1[k] != arr2[l] || arr1[k] == arr2[l]));
          loop invariant (0 < \at(arr1_len,Pre) && 0 < \at(arr2_len,Pre)) ==> (0 <= i <= arr1_len && 0 <= j <= arr2_len);
          loop invariant (0 < \at(arr1_len,Pre) && 0 < \at(arr2_len,Pre)) ==> (i <= arr1_len && j <= arr2_len);
          loop invariant (!(0 < \at(arr1_len,Pre) && 0 < \at(arr2_len,Pre))) ==> ((j == 0)&&(i == 0)&&(n == \at(n,Pre))&&(arr2_len == \at(arr2_len,Pre))&&(arr2 == \at(arr2,Pre))&&(arr1_len == \at(arr1_len,Pre))&&(arr1 == \at(arr1,Pre)));
          loop invariant n == \at(n,Pre);
          loop invariant arr2_len == \at(arr2_len,Pre);
          loop invariant arr2 == \at(arr2,Pre);
          loop invariant arr1_len == \at(arr1_len,Pre);
          loop invariant arr1 == \at(arr1,Pre);
          loop invariant \forall integer k; 0 <= k < arr2_len ==> arr2[k] == \at(arr2[k], Pre);
          loop invariant \forall integer k; 0 <= k < arr1_len ==> arr1[k] == \at(arr1[k], Pre);
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
