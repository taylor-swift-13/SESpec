
/*@
logic integer neq_count(int *a, integer l, integer u, int x) =
  l >= u ? 0 : ((a[l] != x) ? 1 : 0) + neq_count(a, l + 1, u, x);
*/

/*@ logic integer neq_pair_count(int *a, integer l, integer u) =
      l >= u ? 0 : neq_count(a, l + 1, u, a[l]) + neq_pair_count(a, l + 1, u);
*/
/*@
  requires 0 <= arr_len;
  requires arr_len > 1 ==> \valid_read(arr + (0 .. arr_len - 1));
  assigns \nothing;
  ensures arr_len <= 1 ==> \result == 0;
  ensures \result >= 0;
*/
int foo241(int *arr, int arr_len, int n)
{
  if (arr_len <= 1) {
    return 0;
  }

  int count = 0;
  int length = arr_len;

  /*@
    loop invariant 0 <= i <= length - 1;
    loop invariant 0 <= count;
    loop assigns i, count;
    loop variant length - 1 - i;
  */
  for (int i = 0; i < length - 1; i++) {

    /*@
      loop invariant i + 1 <= j <= length;
      loop invariant 0 <= count;
      loop assigns j, count;
      loop variant length - j;
    */
    for (int j = i + 1; j < length; j++) {
      if (arr[i] != arr[j]) {
        count++;
      }
    }
  }

  return count;
}
