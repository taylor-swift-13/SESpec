
/*@ */

 /*@
  requires 0 <= n <= arr_len;
  requires \valid(arr + (0 .. n - 1));
*/

int foo162(int * arr, int arr_len, int n) {

  int i = 0;

  /*@
    loop invariant 0 <= i <= n;
    loop invariant \forall integer k; 0 <= k < i ==> (arr[k] <= 0 || arr[k] > n || arr[k] == k + 1);
    loop assigns i, arr[..];
  */
  while (i < n) {
    if (arr[i] <= 0 || arr[i] > n || arr[i] == i + 1) {
      i++;
    } else {
      int temp = arr[i];
      arr[i] = arr[temp - 1];
      arr[temp - 1] = temp;
    }
  }

  /*@
    loop invariant 0 <= i <= n;
    loop invariant \forall integer k; 0 <= k < i ==> arr[k] == k + 1;
    loop assigns i;
  */
  for (i = 0; i < n; i++) {
    if (arr[i] != i + 1) {
      return i + 1;
    }
  }

  return n + 1;
}
