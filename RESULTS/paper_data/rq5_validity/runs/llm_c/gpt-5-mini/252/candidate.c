int getPairsCount(int * arr, int arr_len, int n, int sum);

/*@
    requires 0 <= n <= arr_len;
    requires n == 0 || \valid(arr + (0 .. n-1));
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= n*(n-1)/2;
    ensures \result == \sum integer i; 0 <= i < n; \sum integer j; i+1 <= j < n; (arr[i] + arr[j] == sum ? 1 : 0);
*/
int getPairsCount(int * arr, int arr_len, int n, int sum) {

        int count = 0;
        /*@
            loop invariant 0 <= i <= n;
            loop invariant count == \sum integer ii; 0 <= ii < i; \sum integer jj; ii+1 <= jj < n; (arr[ii] + arr[jj] == sum ? 1 : 0);
            loop assigns i, count;
            loop variant n - i;
        */
        for (int i = 0; i < n; i++) {
            /*@
                loop invariant i+1 <= j <= n;
                loop invariant count == \sum integer ii; 0 <= ii < i; \sum integer jj; ii+1 <= jj < n; (arr[ii] + arr[jj] == sum ? 1 : 0)
                                              + \sum integer jj; i+1 <= jj < j; (arr[i] + arr[jj] == sum ? 1 : 0);
                loop assigns j, count;
                loop variant n - j;
            */
            for (int j = i + 1; j < n; j++) {
                if (arr[i] + arr[j] == sum) {
                    count++;
                }
            }
        }
        return count;
}
