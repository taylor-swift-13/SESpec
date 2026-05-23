
/*@
  // Count of equal-pair steps taken so far, given the current indices i and j.
  // It reflects exactly the number of iterations up to the point where
  // arr[i]==arr[j] was taken and both indices advanced together.
  logic integer cnt_eq_steps{L}(int* arr, integer n, integer i, integer j) =
    0;

*/

/*@ requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
    requires \valid_read(arr + (0 .. \at(arr_len,Pre)-1));
    requires 0 <= n <= \at(arr_len,Pre);
*/
int foo70_c211(int * arr, int arr_len, int n) {

        int count = 0;
        int i = 0;
        int j = 1;

        /*@
          loop invariant (0 < \at(n,Pre) && 1 < \at(n,Pre)) ==> (
            0 <= i <= n &&
            0 <= j <= n &&
            i <= j &&
            (i == 0 ==> j >= 1) &&
            count >= 0
          );
          loop invariant (0 < \at(n,Pre) && 1 < \at(n,Pre)) ==> (
            count <= i && count <= j
          ) ;
          loop invariant (!(0 < \at(n,Pre) && 1 < \at(n,Pre))) ==> ((j == 1)&&(i == 0)&&(count == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < n ==> \valid_read(arr + k) ;
          loop assigns i, j, count;
        */
        while (i < n && j < n) {
            if (arr[i] == arr[j]) {
                i++;
                j++;
                count++;
            } else if (arr[i] > arr[j]) {
                i++;
            } else {
                j++;
            }
        }

        return count;
}
