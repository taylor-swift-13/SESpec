/*@
    requires \valid(arr+(0..arr_len-1));
    requires 0 <= n <= arr_len;
    ensures \result >= 0;
    ensures \result == \sum(0 <= i < n, \sum(i+1 <= j < n, (arr[i] + arr[j] == sum ? 1 : 0)));
    assigns \nothing;
*/
int getPairsCount(int * arr, int arr_len, int n, int sum) {

        int count = 0;
        /*@
            loop invariant 0 <= i <= n;
            loop invariant count == \sum(0 <= k < i, \sum(k+1 <= l < n, (arr[k] + arr[l] == sum ? 1 : 0)));
            loop assigns i, count;
        */
        for (int i = 0; i < n; i++) {
            /*@
                loop invariant i+1 <= j <= n;
                loop invariant count == \sum(0 <= k < i, \sum(k+1 <= l < n, (arr[k] + arr[l] == sum ? 1 : 0)))
                                      + \sum(i+1 <= l < j, (arr[i] + arr[l] == sum ? 1 : 0));
                loop assigns j, count;
            */
            for (int j = i + 1; j < n; j++) {
                if (arr[i] + arr[j] == sum) {
                    count++;
                }
            }
        }
        return count;
}
