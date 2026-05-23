int minOps(int * arr, int arr_len, int n, int k);

/*@
    requires arr != \null;
    requires n > 0;
    requires arr_len >= n;
    requires k > 0;
    requires \valid(arr + (0 .. arr_len-1));
    assigns \nothing;
    ensures \exists integer m;
              (\forall integer j; 0 <= j < n ==> arr[j] <= m)
           && (\exists integer j; 0 <= j < n && arr[j] == m)
           && (
                 ((\exists integer i; 0 <= i < n && (m - arr[i]) % k != 0) <==> \result == -1)
              && ((\forall integer i; 0 <= i < n ==> (m - arr[i]) % k == 0) ==> \result == \sum integer i; 0 <= i < n; (m - arr[i]) / k)
              );
*/
int minOps(int * arr, int arr_len, int n, int k) {

        int max1 = arr[0];
        /*@
            loop invariant 1 <= i <= n;
            loop invariant \forall integer j; 0 <= j < i ==> arr[j] <= max1;
            loop invariant \exists integer j; 0 <= j < i && arr[j] == max1;
            loop assigns i, max1;
            loop variant n - i;
        */
        for (int i = 1; i < n; i++) {
            if (arr[i] > max1) {
                max1 = arr[i];
            }
        }
        int res = 0;
        /*@
            loop invariant 0 <= i <= n;
            loop invariant \forall integer j; 0 <= j < i ==> (max1 - arr[j]) % k == 0;
            loop invariant res == \sum integer j; 0 <= j < i; (max1 - arr[j]) / k;
            loop assigns i, res;
            loop variant n - i;
        */
        for (int i = 0; i < n; i++) {
            if ((max1 - arr[i]) % k != 0) {
                return -1;
            } else {
                res += (max1 - arr[i]) / k;
            }
        }
        return res;
}
