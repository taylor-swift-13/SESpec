int findElement(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int count);

 /*@
    requires arr != \null;
    requires arr_len > 0;
    requires \valid(arr + (0 .. arr_len-1));
    requires ranges != \null;
    requires ranges_rows >= 0;
    requires ranges_cols >= 2;
    requires 0 <= array <= ranges_rows;
    requires 0 <= count < arr_len;

    // each row pointer in ranges is valid for ranges_cols elements
    requires \forall integer ri; 0 <= ri < ranges_rows ==> ranges[ri] != \null && \valid(ranges[ri] + (0 .. ranges_cols-1));

    // for the rows that may be inspected, the two columns denote indices within arr
    requires \forall integer ri; 0 <= ri < array ==>
                (0 <= ranges[ri][0] && ranges[ri][0] <= ranges[ri][1] && ranges[ri][1] < arr_len);

    assigns \nothing;

    // result is an element taken from arr
    ensures \exists integer k; 0 <= k < arr_len && \result == arr[k];
 */
int findElement(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int count) {

        /*@
            loop invariant -1 <= r && r < array;
            loop invariant 0 <= count < arr_len;
            loop assigns r, count;
            loop variant r + 1;
        */
        for (int r = array - 1; r >= 0; r--) {
            int j = ranges[r][0];
            int top = ranges[r][1];
            if (j <= count && top >= count) {
                if (count == j) {
                    count = top;
                } else {
                    count = count - 1;
                }
            }
        }
        return arr[count];
}
