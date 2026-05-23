/*@
    requires arr != \null;
    requires arr_len >= 0;
    requires 0 <= n <= arr_len;
    requires \valid(arr + (0 .. arr_len - 1));
    assigns \nothing;
    ensures 0 <= \result <= n*(n-1)/2;
    ensures \result == \sum integer ii; 0 <= ii < n; \sum integer jj; ii < jj < n; (arr[ii] > arr[jj] ? 1 : 0);
*/
int getInvCount(int * arr, int arr_len, int n);

int getInvCount(int * arr, int arr_len, int n) {

        int invCount = 0;
        /*@
            loop invariant 0 <= i <= n;
            loop invariant 0 <= invCount <= n*(n-1)/2;
            loop invariant invCount == \sum integer ii; 0 <= ii < i; \sum integer jj; ii < jj < n; (arr[ii] > arr[jj] ? 1 : 0);
            loop assigns i, invCount;
            loop variant n - i;
        */
        for (int i = 0; i < n; i++) {
            /*@
                loop invariant i + 1 <= j <= n;
                loop invariant 0 <= invCount <= n*(n-1)/2;
                loop invariant invCount == \sum integer ii; 0 <= ii < i; \sum integer jj; ii < jj < n; (arr[ii] > arr[jj] ? 1 : 0)
                                 + \sum integer jj; i < jj < j; (arr[i] > arr[jj] ? 1 : 0);
                loop assigns j, invCount;
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
