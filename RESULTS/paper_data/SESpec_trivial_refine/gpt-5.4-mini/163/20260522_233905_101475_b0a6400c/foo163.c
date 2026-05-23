
/*@
  requires arr_len >= 0;
  requires arr == \null || \valid_read(arr + (0 .. arr_len - 1));
  assigns \nothing;
  ensures arr == \null ==> \result == -1;
  ensures arr != \null && arr_len == 1 ==> \result == 0;
  ensures arr != \null && arr_len > 1 ==> \result >= 0;
  ensures arr != \null && arr_len > 1 ==> \result <= arr_len * (arr_len - 1) / 2;
*/
int foo163(int *arr, int arr_len, int n)
{
  (void)n;

  if (arr == 0) {
    return -1;
  }
  if (arr_len == 1) {
    return 0;
  }

  int evenPairCount = 0;

  /*@
    loop invariant 0 <= i <= arr_len;
    loop invariant 0 <= evenPairCount <= i * (2 * arr_len - i - 1) / 2;
    loop assigns i, evenPairCount;
    loop variant arr_len - i;
  */
  for (int i = 0; i < arr_len; i++) {
    /*@
      loop invariant i + 1 <= c <= arr_len;
      loop invariant 0 <= evenPairCount <= i * (2 * arr_len - i - 1) / 2 + (c - (i + 1));
      loop assigns c, evenPairCount;
      loop variant arr_len - c;
    */
    for (int c = i + 1; c < arr_len; c++) {
      int odd = arr[i];
      int b = arr[c];
      int even = odd ^ b;
      if ((even & 1) == 0) {
        evenPairCount++;
      }
    }
  }

  return evenPairCount;
}
