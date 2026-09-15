/*@
    requires \valid(arr + (0 .. arr_len-1));
    requires 0 <= num <= ranges_len;
    requires ranges_cols >= 2;
    requires \valid(ranges + (0 .. num-1));
    requires \forall integer i; 0 <= i < num ==> \valid(ranges[i] + (0 .. 1));
    requires \forall integer i; 0 <= i < num ==> 0 <= ranges[i][0] <= ranges[i][1] < arr_len;
    requires 0 <= count < arr_len;

    assigns \nothing;

    ensures 0 <= count < arr_len;
    ensures \result == arr[count];
*/
int findElement(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int num, int count) {

    /*@ 
        loop invariant -1 <= r < num;
        loop invariant 0 <= count < arr_len;
        loop assigns r, count;
        loop variant r+1;
    */
    for (int r = num - 1; r >= 0; r--) {
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
