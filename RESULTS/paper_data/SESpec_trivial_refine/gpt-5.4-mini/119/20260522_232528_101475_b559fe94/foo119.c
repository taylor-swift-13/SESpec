
/*@
  requires arr != \null;
  requires arr_len >= 0;
  requires \valid(arr + (0 .. arr_len));
  assigns \nothing;
  ensures \result == 0 || \result == 1;
  ensures \result == 1 ==> (\forall integer k; 0 <= k < arr_len ==> arr[k] > arr[k+1]);
  ensures \result == 0 ==> (\exists integer k; 0 <= k < arr_len && arr[k] <= arr[k+1]);
*/
int foo119(int *arr, int arr_len)
{
  int n = arr_len;

  if (n < 1) {
    return 1;
  }

  /*@
    loop assigns i;
    loop invariant 0 <= i <= n;
    loop invariant \forall integer k; 0 <= k < i ==> arr[k] > arr[k+1];
    loop variant n - i;
  */
  for (int i = 0; i < n; i++) {
    if (arr[i] <= arr[i + 1]) {
      return 0;
    }
  }

  return 1;
}
