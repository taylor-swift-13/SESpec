
/*@
  requires arr_len >= 0;
  requires \valid(arr + (0 .. arr_len));
  assigns \nothing;

  behavior short:
    assumes arr_len < 2;
    ensures \result == 1;

  behavior sorted:
    assumes arr_len >= 2;
    assumes \forall integer k; 0 <= k < arr_len ==> arr[k] < arr[k+1];
    ensures \result == 1;

  behavior unsorted:
    assumes arr_len >= 2;
    assumes \exists integer k; 0 <= k < arr_len && arr[k] >= arr[k+1];

  complete behaviors;
  disjoint behaviors;
*/
int foo113(int *arr, int arr_len)
{
  int n = arr_len;

  if (n < 2) {
    return 1;
  }

  /*@
    loop invariant 0 <= i <= n - 1;
    loop invariant \forall integer k; 0 <= k < i ==> arr[k] < arr[k+1];
    loop assigns i;
    loop variant (n - 1) - i;
  */
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] >= arr[i + 1]) {
      return 0;
    }
  }

  return 1;
}
