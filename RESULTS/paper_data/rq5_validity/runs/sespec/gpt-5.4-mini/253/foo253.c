
/*@
logic integer inv_between(int *arr, integer n, integer i, integer j) =
  j <= i + 1 ? 0 : inv_between(arr, n, i, j - 1) + (arr[i] > arr[j - 1] ? 1 : 0);

logic integer inv_prefix(int *arr, integer n, integer i) =
  i <= 0 ? 0 : inv_prefix(arr, n, i - 1) + inv_between(arr, n, i - 1, n);
*/

/*@
  requires 0 <= n <= arr_len;
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] && arr[i] <= 100;
  assigns \nothing;
  ensures \result >= 0;
  ensures \result >= 0;
  ensures \result >= 0;
  ensures \result >= 0;
*/
int foo253(int * arr, int arr_len, int n) {

        int invCount = 0;

            /*@
          loop invariant 0 <= i;
          loop invariant invCount == inv_prefix(arr, n, i);
          loop invariant 0 <= invCount;
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop assigns i, invCount;
            */
            for (int i = 0; i < n; i++) {
            
            /*@
          loop invariant 0 <= i <= n;
          loop invariant i + 1 <= j <= n;
          loop invariant invCount == inv_prefix(arr, n, i) + inv_between(arr, n, i, j);
          loop invariant 0 <= invCount;
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop assigns j, invCount;
            */
            for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j]) {
                    invCount++;
                }
            }
            
        }
            
        return invCount;
}
