/*@
    requires \valid_read(arr + (0 .. arr_len - 1));
    requires rotations >= 0;
    requires index >= 0;
    requires index < arr_len;
    requires ranges_len >= rotations;
    requires ranges_rows >= ranges_len;
    requires ranges_cols >= 2;
    requires \valid_read(ranges + (0 .. ranges_len - 1));
    requires \forall integer i; 0 <= i < ranges_len ==> \valid_read(ranges[i] + (0 .. 1));
    assigns \nothing;
    ensures \result == arr[\old(index)];
*/
int findElement(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int rotations, int index);

int findElement(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int rotations, int index) {

        /*@
            loop invariant -1 <= i < rotations;
            loop invariant index >= 0;
            loop invariant index < arr_len;
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
