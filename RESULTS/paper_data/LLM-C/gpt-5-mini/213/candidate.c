int findElement(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int rotations, int index);

 /*@
    requires arr != \null;
    requires 0 <= arr_len;
    requires \valid(arr + (0 .. arr_len - 1));
    requires rotations >= 0;
    requires 0 <= rotations <= ranges_rows;
    requires ranges_cols >= 2;
    requires ranges != \null;
    requires \valid(ranges + (0 .. rotations - 1));
    requires \forall integer k; 0 <= k < rotations ==> \valid(ranges[k] + (0 .. ranges_cols - 1));
    requires \forall integer k; 0 <= k < rotations ==> 0 <= ranges[k][0] <= ranges[k][1] < arr_len;
    requires 0 <= index < arr_len;
    assigns \nothing;
    ensures 0 <= \at(index, Post) < arr_len;
    ensures \result == arr[\at(index, Post)];
 */
int findElement(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int rotations, int index) {

        /*@
            loop invariant -1 <= i && i < rotations;
            loop invariant 0 <= index < arr_len;
            loop assigns i, index;
            loop variant i + 1;
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
