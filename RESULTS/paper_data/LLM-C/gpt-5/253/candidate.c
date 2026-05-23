int getInvCount(int * arr, int arr_len, int n);

/*@ 
  requires 0 <= arr_len;
  requires 0 <= n && n <= arr_len;
  requires arr != \null;
  requires \valid_read(arr + (0 .. arr_len-1));
  assigns \nothing;
  ensures 0 <= \result <= (n * (n - 1)) / 2;
  ensures \result == \sum(integer i0, 0, n-1, 
                          \sum(integer j0, i0+1, n-1, (arr[i0] > arr[j0] ? 1 : 0)));
*/
int getInvCount(int * arr, int arr_len, int n) {

        int invCount = 0;

        /*@
          loop invariant 0 <= i <= n;
          loop invariant 0 <= invCount <= (n * (n - 1)) / 2;
          loop invariant invCount == \sum(integer i0, 0, i-1,
                                          \sum(integer j0, i0+1, n-1, (arr[i0] > arr[j0] ? 1 : 0)));
          loop variant n - i;
        */
        for (int i = 0; i < n; i++) {
            /*@
              loop invariant 0 <= i < n;
              loop invariant i + 1 <= j <= n;
              loop invariant 0 <= invCount <= (n * (n - 1)) / 2;
              loop invariant invCount ==
                               \sum(integer i0, 0, i-1,
                                    \sum(integer j0, i0+1, n-1, (arr[i0] > arr[j0] ? 1 : 0)))
                             + \sum(integer k, i+1, j-1, (arr[i] > arr[k] ? 1 : 0));
              loop variant n - j;
            */
            for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j]) {
                    invCount++;
                }
            }
        }
        return invCount;
}
