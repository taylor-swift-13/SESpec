
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;
  ensures n == 0 ==> \result == \("NO");
  ensures n > 0 ==> (
    (\forall integer i; 0 <= i < n ==> arr[i] == arr[0]) ? \result == \("YES") : \result == \("NO")
  );
*/
const char * foo152(int * arr, int arr_len, int n) {

    if (n == 0) {
        return "NO";
    }

    int firstElement = arr[0];
    
    /*@
      loop invariant 1 <= i <= n;
      loop invariant \forall integer k; 0 <= k < i ==> arr[k] == firstElement;
      loop invariant count_eq(arr, 0, i, firstElement) == i;
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
