int frequencyOfSmallest(int n, int * arr, int arr_len);

/*@ 
  requires arr_len >= 0;
  requires 0 <= n <= arr_len;
  requires n == 0 || \valid_read(arr + (0..n-1));
  assigns \nothing;
  ensures n == 0 ==> \result == 0;
  ensures n > 0 ==> 1 <= \result <= n;
  ensures n > 0 ==> 
    (\exists integer j; 0 <= j < n &&
      (\forall integer i0; 0 <= i0 < n ==> arr[i0] >= arr[j]) &&
      \result == \numof integer k; 0 <= k < n && arr[k] == arr[j]);
*/
int frequencyOfSmallest(int n, int * arr, int arr_len) {

        if (n == 0) {
            return 0;
        }

        int min = arr[0];
        int count = 1;

        /*@
          loop invariant 1 <= i <= n;
          loop invariant (\forall integer k; 0 <= k < i ==> arr[k] >= min);
          loop invariant (\exists integer j; 0 <= j < i && arr[j] == min);
          loop invariant count == \numof integer k; 0 <= k < i && arr[k] == min;
          loop assigns min, count, i;
          loop variant n - i;
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
