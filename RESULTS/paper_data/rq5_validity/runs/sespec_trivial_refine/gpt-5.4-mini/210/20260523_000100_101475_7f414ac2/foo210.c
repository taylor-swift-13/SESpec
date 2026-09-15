
        /*@
        */

/*@
  requires arr_len > 0;
  requires \valid_read(arr + (0 .. arr_len - 1));

  requires 0 <= array;
  requires 0 <= ranges_rows;
  requires 0 <= ranges_cols;
  requires ranges_cols >= 2;
  requires array <= ranges_rows;
  requires \valid_read(ranges + (0 .. array - 1));
  requires \forall integer r; 0 <= r < array ==> \valid_read(ranges[r] + (0 .. 1));

  requires 0 <= count < arr_len;
  requires \forall integer r; 0 <= r < array ==>
              0 <= ranges[r][0] < arr_len &&
              0 <= ranges[r][1] < arr_len;

  assigns \nothing;
  ensures 0 <= \result < arr_len;
  ensures \result == arr[\at(count,Post)];
*/
int foo210(int *arr, int arr_len, int **ranges, int ranges_len,
           int ranges_rows, int ranges_cols, int array, int count)
{
  /*@
    loop invariant -1 <= r < array;
    loop invariant 0 <= count < arr_len;
    loop invariant \forall integer k; 0 <= k < array ==>
                      \valid_read(ranges[k] + (0 .. 1));
    loop assigns r, count;
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
