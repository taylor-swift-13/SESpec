
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/
        
/*@
  requires arr_len >= 0;
  requires n >= 0;
  requires arr_len >= n;
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns arr[0..arr_len-1];
  ensures 1 <= \result && \result <= n + 1;
  ensures (\exists integer v; 1 <= v && v <= n && \old(count_eq(arr, 0, arr_len, v)) == 0)
           ==>
           (1 <= \result && \result <= n);
*/
int foo162(int * arr, int arr_len, int n) {

    int i = 0;

    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= n;
      loop invariant 0 <= arr_len;
      loop invariant n <= arr_len;
      loop invariant \forall integer k; 0 <= k < arr_len ==> \valid(&arr[k]);
      loop invariant n == \at(n,Pre);
      loop invariant arr_len == \at(arr_len,Pre);
      loop assigns i, arr[0..arr_len-1];
    */
    while (i < n) {
        if (arr[i] <= 0 || arr[i] > n || arr[i] == i + 1) {
            i++;
        } else {
            int temp = arr[i];
            arr[i] = arr[temp - 1];
            arr[temp - 1] = temp;
        }
    }

    /*@
      loop invariant 0 <= i <= n;
      loop invariant \forall integer k; 0 <= k < i ==> arr[k] == k + 1;
      loop assigns \nothing;
    */
    for (i = 0; i < n; i++) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }
    return n + 1;
}
