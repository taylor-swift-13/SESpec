/*@
    requires \valid(arr + (0..arr_len-1));
    requires \valid(ranges + (0..ranges_len-1));
    requires \forall integer i; 0 <= i < ranges_len ==> \valid(ranges[i] + (0..ranges_cols-1));
    requires ranges_cols == 2;
    requires 0 <= rotations <= ranges_len;
    requires 0 <= index < arr_len;
    ensures 0 <= \result < arr_len;
    assigns index;
*/
int findElement(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int rotations, int index);

int findElement(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int rotations, int index) {

    /*@
        loop invariant -1 <= i < rotations;
        loop invariant 0 <= index < arr_len;
        loop assigns i, index;
        loop variant i;
    */
    for (int i = rotations - 1; i >= 0; i--) {
        int left = ranges[i][0];
        int right = ranges[i][1];
        if (left <= index && right >= index) {
            if (index == left) {
                index = right;
            } else {
                index = index - 1;
            }
        }
    }
    return arr[index];
}
