
/*@ logic integer max2(integer x, integer y) = x >= y ? x : y; */
/*@ logic integer best_end(integer i, integer j, int *a) =
      j == 0 ? a[i] :
      max2(
        best_end(i, j - 1, a),
        (a[i] > a[j - 1] ? best_end(j - 1, j - 1, a) * a[i] : best_end(i, j - 1, a))
      ); */
/*@ logic integer best_value(integer n, int *a) =
      n == 1 ? best_end(0, 0, a) :
      max2(best_value(n - 1, a), best_end(n - 1, n - 1, a)); */
/*@ 
  requires 0 < n <= arr_len;
  requires \valid_read(arr + (0 .. n-1));
  assigns \result \from arr[0 .. n-1], n;
  ensures \true;
*/
int foo157(int *arr, int arr_len, int n) {

        int *mpis = (int *)malloc(sizeof(int) * n);
        int mpis_len = n;

        /*@
          loop invariant 0 <= i <= n;
          loop assigns i, mpis[0 .. n-1];
        */
        for (int i = 0; i < n; i++) {
            mpis[i] = arr[i];
        }

        /*@
          loop invariant 1 <= i <= n;
          loop assigns i, mpis[0 .. n-1];
        */
        for (int i = 1; i < n; i++) {

            /*@
              loop invariant 0 <= j <= i;
              loop assigns j, mpis[i];
            */
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j] && mpis[i] < (mpis[j] * arr[i])) {
                    mpis[i] = mpis[j] * arr[i];
                }
            }

        }

        int max = mpis[0];

        /*@
          loop invariant 1 <= i <= n;
          loop invariant \forall integer k; 0 <= k < i ==> max >= mpis[k];
          loop invariant \exists integer k; 0 <= k < i && max == mpis[k];
          loop assigns i, max;
        */
        for (int i = 1; i < n; i++) {
            if (mpis[i] > max) {
                max = mpis[i];
            }
        }

        return max;
}
