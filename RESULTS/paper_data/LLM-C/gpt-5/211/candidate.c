int findMinSwaps(int * arr, int arr_len, int n);

/*@ 
  requires arr_len >= 0;
  requires 0 <= n <= arr_len;
  requires arr_len == 0 || \valid_read(arr + (0 .. arr_len-1));
  assigns \nothing;
  ensures 0 <= \result;
  ensures n <= 1 ==> \result == 0;
  ensures n >= 1 ==> \result <= n - 1;
*/
int findMinSwaps(int * arr, int arr_len, int n) {

        int count = 0;
        int i = 0;
        int j = 1;

        /*@
          loop invariant 0 <= i <= n;
          loop invariant 0 <= j <= n;
          loop invariant 0 <= count;
          loop invariant n <= 1 ==> count == 0;
          loop invariant n >= 1 ==> count <= n - 1;
          loop invariant count <= i;
          loop invariant count <= j;
          loop assigns i, j, count;
          loop variant 2 * n - (i + j);
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
