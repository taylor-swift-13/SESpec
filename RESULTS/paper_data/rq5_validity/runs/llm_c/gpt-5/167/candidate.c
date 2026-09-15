int minOps(int * arr, int arr_len, int n, int k);

/*@ 
  logic integer max_of{L}(int *a, integer n) =
    n <= 0 ? 0 :
    (n == 1 ? \at(a[0],L)
            : (max_of{L}(a,n-1) >= \at(a[n-1],L) ? max_of{L}(a,n-1) : \at(a[n-1],L)));

  requires arr != \null;
  requires 1 <= n <= arr_len;
  requires \valid_read(arr + (0 .. arr_len-1));
  requires k != 0;

  assigns \nothing;

  behavior invalid:
    assumes \exists integer i; 0 <= i < n && ((max_of{Pre}(arr,n) - arr[i]) % k) != 0;
    ensures \result == -1;

  behavior valid:
    assumes \forall integer i; 0 <= i < n ==> ((max_of{Pre}(arr,n) - arr[i]) % k) == 0;
    ensures \result == \sum_{integer i=0 .. n-1} ((max_of{Pre}(arr,n) - arr[i]) / k);

  complete behaviors;
  disjoint behaviors;
*/
int minOps(int * arr, int arr_len, int n, int k) {

        int max1 = arr[0];
        /*@ 
          loop invariant 1 <= i <= n;
          loop invariant \forall integer j; 0 <= j < i ==> arr[j] <= max1;
          loop invariant \exists integer j; 0 <= j < i ==> max1 == arr[j];
          loop assigns i, max1;
          loop variant n - i;
        */
        for (int i = 1; i < n; i++) {
            if (arr[i] > max1) {
                max1 = arr[i];
            }
        }
        /*@ assert \forall integer j; 0 <= j < n ==> arr[j] <= max1; */
        /*@ assert \exists integer j; 0 <= j < n && arr[j] == max1; */
        int res = 0;
        /*@ 
          loop invariant 0 <= i <= n;
          loop invariant \forall integer j; 0 <= j < i ==> ((max1 - arr[j]) % k) == 0;
          loop invariant \let M = max1; res == \sum_{integer j=0 .. i-1} ((M - arr[j]) / k);
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
