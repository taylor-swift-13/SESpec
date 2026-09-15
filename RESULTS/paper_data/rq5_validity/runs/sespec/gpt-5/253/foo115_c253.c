
/*@
  logic integer invpair_count(int* a, integer i, integer j) =
    i >= j ? 0
           : invpair_count(a, i, j - 1) + (a[j - 1] < a[i] ? 1 : 0);
*/

/*@
  logic integer total_inv_up_to(int* a, integer n, integer i) =
    i <= 0 ? 0
           : total_inv_up_to(a, n, i - 1) + invpair_count(a, i - 1, n);
*/
        
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  requires 0 <= n <= arr_len;
  assigns \nothing;
*/
int foo115_c253(int * arr, int arr_len, int n) {

        int invCount = 0;

        /*@
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < n ==> arr[k] == \at(arr[k],Pre);
          loop assigns i, invCount;
        */
        for (int i = 0; i < n; i++) {

            /*@
              loop invariant i + 1 <= j <= n;
              loop invariant \forall integer k; 0 <= k < n ==> arr[k] == \at(arr[k],Pre);
              loop assigns invCount, i, j;
            */
            for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j]) {
                    invCount++;
                }
            }
        }

        return invCount;
}
