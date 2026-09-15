
/*@ 
  predicate ArrUnchanged(int* a, integer len, int* a0) =
    \forall integer k; 0 <= k < len ==> a[k] == a0[k];
*/

/*@
  predicate ResultSpec(int result, int* a, integer n, int x) =
    result == -1 || (0 <= result < n && a[result] == x);
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  requires n == arr_len;
  assigns \nothing;
  ensures \valid(&arr[0] + (0..arr_len-1));
  ensures ArrUnchanged(arr, arr_len, \at(arr,Pre));
  ensures \result == \result;
*/
int foo95(int * arr, int arr_len, int x, int n) {

        int i = 0;
        int j = n - 1;
        int result = -1;

        
            
        /*@
          loop invariant (0 <= \at(n,Pre) - 1) ==> (((result == -1)&&(j == \at(n,Pre) - 1)&&(i == 0)&&(n == \at(n,Pre))&&(x == \at(x,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (result != -1 ==> arr[result] == x));
          loop invariant (!(0 <= \at(n,Pre) - 1)) ==> ((result == -1)&&(j == \at(n,Pre) - 1)&&(i == 0)&&(n == \at(n,Pre))&&(x == \at(x,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant n == \at(n,Pre);
          loop invariant x == \at(x,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant ArrUnchanged(arr, \at(arr_len,Pre), \at(arr,Pre));
          loop assigns result, i, j;
        */
            while (i <= j) {
            int mid = (i + j) / 2;
            if (arr[mid] == x) {
                result = mid;
                i = mid + 1;
            } else if (arr[mid] < x) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
            

        return result;
}
