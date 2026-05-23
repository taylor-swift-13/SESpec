
/*@
  logic integer eqpairs{L}(int* a, integer n, integer i, integer j) =
    (i >= n || j >= n) ? 0
    : (a[i] == a[j] ? 1 + eqpairs(a, n, i + 1, j + 1)
                    : (a[i] > a[j] ? eqpairs(a, n, i + 1, j)
                                   : eqpairs(a, n, i, j + 1)));
*/

/*@
  requires 0 <= n <= arr_len;
  requires \valid_read(arr + (0 .. n-1));
  requires \forall integer k1, k2; 0 <= k1 < k2 < n ==> arr[k1] <= arr[k2];
  assigns \nothing;
  ensures 0 <= \result <= n;
  ensures n == \old(n);
  ensures arr_len == \old(arr_len);
  ensures arr == \old(arr);
  ensures \forall integer k; 0 <= k < n ==> arr[k] == \at(arr[k], Pre);
*/
int foo211(int * arr, int arr_len, int n) {

        int count = 0;
        int i = 0;
        int j = 1;

        /*@ 
          loop invariant 0 <= i <= n;
          loop invariant 0 <= count <= i && 0 <= count <= j;
          loop invariant (i == 0 && j == 1) || (i + j >= 1);
          loop invariant \forall integer k; 0 <= k < n ==> arr[k] == \at(arr[k], Pre);
          loop invariant (i >= n || j >= n) ==> (i == n || j == n);
          loop invariant (0 < \at(n,Pre) && 1 < \at(n,Pre)) ==> (0 <= i <= n && 0 <= j <= n);
          loop invariant (0 < \at(n,Pre) && 1 < \at(n,Pre)) ==> (0 <= i && i <= n);
          loop invariant (0 < \at(n,Pre) && 1 < \at(n,Pre)) ==> (0 <= j && j <= n);
          loop invariant (!(0 < \at(n,Pre) && 1 < \at(n,Pre))) ==> ((j == 1)&&(i == 0)&&(count == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < n ==> arr[k] == \at(arr[k], Pre);
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
