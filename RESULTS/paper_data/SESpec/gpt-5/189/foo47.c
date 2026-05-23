
/*@ 
  logic integer count_eq_in_range{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq_in_range{L}(a, lo, hi - 1, v) + (\at(a[hi - 1], L) == v ? 1 : 0);
*/

/*@ 
  logic integer min_in_range{L}(int* a, integer lo, integer hi) =
    lo + 1 >= hi ? \at(a[lo], L)
                 : (\at(a[hi - 1], L) < min_in_range{L}(a, lo, hi - 1) 
                      ? \at(a[hi - 1], L) 
                      : min_in_range{L}(a, lo, hi - 1));
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  requires 0 <= n <= arr_len;
  assigns \nothing;   
  ensures n == 0 ==> \result == 0;
*/
int foo47(int n, int * arr, int arr_len) {

        if (n == 0) {
            return 0;
        }

        int min = arr[0];
        int count = 1;

        /*@
          loop invariant 1 <= i;
          loop invariant (i < n) ==> i <= n;
          loop invariant \at(arr_len,Pre) == arr_len;
          loop invariant \at(arr,Pre) == arr;
          loop invariant \at(n,Pre) == n;
          loop invariant \forall integer k; 0 <= k < \at(arr_len,Pre) ==> arr[k] == \at(arr[k],Pre);
          loop invariant 1 <= count <= i;
          loop assigns i, min, count;
        */
        for (int i = 1; i < n; i++) {
            if (min > arr[i]) {
                min = arr[i];
                count = 1;
            } else if (min == arr[i]) {
                count++;
            }
        }

        return count;
}
