
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires leftElement >= 0 && rightElement < a_len;
  requires \exists integer k; leftElement <= k <= rightElement && a[k] == k;
  
  ensures \result >= leftElement && \result <= rightElement + 1;
*/
int foo298(int * a, int a_len, int leftElement, int rightElement) {

    int i = leftElement;
    int j = rightElement;

    /*@
      loop invariant rightElement == \at(rightElement,Pre);
      loop invariant leftElement == \at(leftElement,Pre);
      loop invariant a_len == \at(a_len,Pre);
      loop invariant a == \at(a,Pre);
      loop invariant leftElement <= i && i <= rightElement + 1;
      loop invariant leftElement - 1 <= j && j <= rightElement;
      loop invariant \exists integer k; i <= k <= j ==> a[k] == k;
      loop assigns i, j;
      loop variant j - i;
    */
    while (i <= j) {
        int mid = (i + j) / 2;
        if (a[mid] == mid) {
            i = mid + 1;
        } else {
            j = mid - 1;
        }
    }

    return i;
}
