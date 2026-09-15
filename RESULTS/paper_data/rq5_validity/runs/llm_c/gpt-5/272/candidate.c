const char * uniqueElement(int * arr, int arr_len, int n);

/*@
  requires arr_len >= 0;
  requires n >= 0 && n <= arr_len;
  requires n == 0 || \valid_read(arr + (0..n-1));
  assigns \nothing;

  behavior empty:
    assumes n == 0;
    ensures \result == "NO";

  behavior equal:
    assumes n > 0 && (\forall integer i; 1 <= i < n ==> arr[i] == arr[0]);
    ensures \result == "YES";

  behavior notequal:
    assumes n > 0 && (\exists integer i; 1 <= i < n && arr[i] != arr[0]);
    ensures \result == "NO";

  complete behaviors;
  disjoint behaviors;
*/
const char * uniqueElement(int * arr, int arr_len, int n) {

        if (n == 0) {
            return "NO";
        }

        /*@ assert n > 0; */

        int firstElement = arr[0];
        /*@
          loop invariant 1 <= i <= n;
          loop invariant (\forall integer k; 1 <= k < i ==> arr[k] == firstElement);
          loop assigns i;
          loop variant n - i;
        */
        for (int i = 1; i < n; i++) {
            if (arr[i] != firstElement) {
                return "NO";
            }
        }
        return "YES";
}
