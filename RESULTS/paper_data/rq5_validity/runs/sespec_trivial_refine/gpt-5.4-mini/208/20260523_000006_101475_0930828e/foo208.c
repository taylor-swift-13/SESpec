
/*@
  predicate ranges_ok{L}(int **ranges, integer n, integer arr_len) =
    \valid_read(ranges + (0 .. n-1)) &&
    \forall integer i; 0 <= i < n ==>
      \valid_read(ranges[i] + (0 .. 1)) &&
      0 <= ranges[i][0] <= ranges[i][1] < arr_len;
*/

/*@
  logic integer foo208_count(int **ranges, integer r, integer count) =
    r < 0 ? count :
    (ranges[r][0] <= count && count <= ranges[r][1] ?
      foo208_count(ranges, r - 1,
        count == ranges[r][0] ? ranges[r][1] : count - 1) :
      foo208_count(ranges, r - 1, count));
*/

/*@
  lemma foo208_count_outside:
    \forall int **ranges, integer r, integer count;
      r >= 0 &&
      !(ranges[r][0] <= count <= ranges[r][1]) ==>
        foo208_count(ranges, r, count) == foo208_count(ranges, r - 1, count);
*/

/*@
  lemma foo208_count_inside_nonfirst:
    \forall int **ranges, integer r, integer count;
      r >= 0 &&
      ranges[r][0] <= count <= ranges[r][1] &&
      count != ranges[r][0] ==>
        foo208_count(ranges, r, count) ==
        foo208_count(ranges, r - 1, count - 1);
*/

/*@
  lemma foo208_count_inside_first:
    \forall int **ranges, integer r, integer count;
      r >= 0 &&
      ranges[r][0] <= count <= ranges[r][1] &&
      count == ranges[r][0] ==>
        foo208_count(ranges, r, count) ==
        foo208_count(ranges, r - 1, ranges[r][1]);
*/

/*@
  requires arr_len > 0;
  requires \valid(arr + (0 .. arr_len-1));
  requires num >= 0;
  requires ranges_ok(ranges, num, arr_len);
  requires 0 <= count < arr_len;
  assigns \nothing;
*/
int foo208(int *arr, int arr_len, int **ranges, int ranges_len, int ranges_rows, int ranges_cols, int num, int count)
{
  /*@ ghost int c0 = count; */

  /*@
    loop invariant -1 <= r < num;
    loop invariant 0 <= count < arr_len;
    loop invariant foo208_count(ranges, r, count) == foo208_count(ranges, num - 1, c0);
    loop assigns r, count;
    loop variant r + 1;
  */
  for (int r = num - 1; r >= 0; r--) {
    /*@ ghost int old_count = count; */
    int j = ranges[r][0];
    int top = ranges[r][1];

    if (j <= count && top >= count) {
      if (count == j) {
        count = top;
        /*@
          assert foo208_count(ranges, r, old_count) == foo208_count(ranges, r - 1, count);
        */
      } else {
        count = count - 1;
        /*@
          assert foo208_count(ranges, r, old_count) == foo208_count(ranges, r - 1, count);
        */
      }
    } else {
      /*@
        assert foo208_count(ranges, r, old_count) == foo208_count(ranges, r - 1, count);
      */
    }
  }

  return arr[count];
}
