/*@
    requires \valid(arr + (0..arr_len-1));
    requires \valid(ranges + (0..ranges_len-1));
    requires \forall integer i; 0 <= i < ranges_len ==> \valid(ranges[i] + (0..ranges_cols-1));
    requires ranges_rows == ranges_len;
    requires ranges_cols >= 2;
    requires 0 <= array <= ranges_len;
    requires 0 <= width < arr_len;
    ensures 0 <= \result < arr_len;
    assigns width;
*/
int findElement(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int width) {

    /*@
        loop invariant -1 <= r < array;
        loop invariant 0 <= width < arr_len;
        loop invariant \forall integer k; r < k < array ==> 
            (ranges[k][0] > width || ranges[k][1] < width);
        loop assigns r, width;
        loop variant r;
    */
    for (int r = array - 1; r >= 0; r--) {
        int j = ranges[r][0];
        int top = ranges[r][1];
        if (j <= width && top >= width) {
            if (width == j) {
                width = top;
            } else {
                width = width - 1;
            }
        }
    }
    return arr[width];
}
