int Binary(int * arr, int arr_len, int key);

/*@
    requires arr_len >= 0;
    requires arr_len == 0 || \valid_read(arr + (0 .. arr_len-1));
    requires \forall integer i; 0 <= i+1 < arr_len ==> arr[i] <= arr[i+1];
    assigns \nothing;
    ensures (\result == -1) <==> (\forall integer i; 0 <= i < arr_len ==> arr[i] != key);
    ensures \result >= 0 ==> 0 <= \result < arr_len;
    ensures \result >= 0 ==> arr[\result] == key;
*/
int Binary(int * arr, int arr_len, int key) {

        if (arr_len == 0) {
            return -1;
        } else {
            int low = 0;
            int high = arr_len;
            int mid =  high / 2;

            /*@
                loop invariant 0 <= low <= high <= arr_len;
                loop invariant low <= mid <= high;
                loop invariant low < high ==> low <= mid < high;
                loop invariant \forall integer j; 0 <= j < low ==> arr[j] < key;
                loop invariant \forall integer j; high <= j < arr_len ==> arr[j] > key;
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
