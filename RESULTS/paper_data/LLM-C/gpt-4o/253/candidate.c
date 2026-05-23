/*@
    requires \valid(arr + (0..arr_len-1));
    requires 0 <= n <= arr_len;
    ensures \result >= 0;
    ensures \result == \sum(0 <= i < n, \sum(i+1 <= j < n, (arr[i] > arr[j] ? 1 : 0)));
    assigns \nothing;
*/
int getInvCount(int * arr, int arr_len, int n);

int getInvCount(int * arr, int arr_len, int n) {

        int invCount = 0;

        /*@
            loop invariant 0 <= i <= n;
            loop invariant invCount == \sum(0 <= k < i, \sum(k+1 <= j < n, (arr[k] > arr[j] ? 1 : 0)));
            loop assigns i, invCount;
            loop variant n - i;
        */
        for (int i = 0; i < n; i++) {
            /*@
                loop invariant i+1 <= j <= n;
                loop invariant invCount == \sum(0 <= k < i, \sum(k+1 <= n, (arr[k] > arr[j] ? 1 : 0)))
                                    + \sum(i+1 <= k < j, (arr[i] > arr[k] ? 1 : 0));
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
