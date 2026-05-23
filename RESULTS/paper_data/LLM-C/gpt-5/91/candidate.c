/*@ predicate nondecreasing{L}(int *a, integer n) =
      \forall integer i, j; 0 <= i <= j < n ==> \at(a[i],L) <= \at(a[j],L);
*/

/*@ requires arr_len >= 0;
    requires arr_len == 0 || \valid_read(arr + (0 .. arr_len - 1));
    requires nondecreasing(arr, arr_len);
    assigns \nothing;

    behavior found:
      ensures 0 <= \result < arr_len ==> arr[\result] == key;

    behavior not_found:
      ensures \result == -1 ==> \forall integer i; 0 <= i < arr_len ==> arr[i] != key;

    ensures \result == -1 || (0 <= \result < arr_len && arr[\result] == key);

    complete behaviors;
    disjoint behaviors;
*/
int Binary(int * arr, int arr_len, int key);

int Binary(int * arr, int arr_len, int key) {

        if (arr_len == 0) {
            return -1;
        } else {
            int low = 0;
            int high = arr_len;
            int mid =  high / 2;

            /*@
              loop invariant 0 <= low <= mid < high <= arr_len;
              loop invariant \forall integer i; 0 <= i < low ==> arr[i] < key;
              loop invariant \forall integer i; high <= i < arr_len ==> arr[i] > key;
              loop invariant mid == low + (high - low) / 2;
              loop assigns low, high, mid;
              loop variant high - low;
            */
            while (low < high && arr[mid] != key) {
                if (arr[mid] < key) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
                mid = low + (high - low) / 2;
            }
            if (low >= high) {
                return -1;
            }
            return mid;
        }
}
