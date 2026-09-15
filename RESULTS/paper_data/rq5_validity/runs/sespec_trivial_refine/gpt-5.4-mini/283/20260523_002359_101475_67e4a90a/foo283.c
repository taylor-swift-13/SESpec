
        /*@
  requires n > 0;
  requires \valid(arr + (0 .. n - 1));
  assigns \nothing;

  behavior found:
    assumes \exists integer k; 0 <= k < n - 1 && k % 2 == 0 && arr[k] != arr[k + 1];
    ensures \exists integer k; 0 <= k < n - 1 && k % 2 == 0 && arr[k] != arr[k + 1] && \result == arr[k];

  behavior not_found:
    assumes \forall integer k; 0 <= k < n - 1 && k % 2 == 0 ==> arr[k] == arr[k + 1];
    ensures \result == arr[n - 1];
    ensures \exists integer k; 0 <= k < n && k == n - 1 && \result == arr[k];
    ensures \forall integer j; 0 <= j < n - 1 && j % 2 == 0 ==> arr[j] == arr[j + 1];

  complete behaviors;
  disjoint behaviors;
*/
int foo283(int *arr, int arr_len, int n)
{
  int i = 0;

  /*@
    loop invariant 0 <= i <= n;
    loop invariant i % 2 == 0;
    loop invariant \forall integer j; 0 <= j < i && j % 2 == 0 ==> arr[j] == arr[j + 1];
    loop assigns i;
    loop variant n - i;
  */
  while (i < n - 1) {
    if (arr[i] == arr[i + 1]) {
      i += 2;
    } else {
      return arr[i];
    }
  }

  return arr[n - 1];
}
