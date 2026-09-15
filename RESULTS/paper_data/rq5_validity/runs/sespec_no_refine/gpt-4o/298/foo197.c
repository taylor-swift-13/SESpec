
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  logic integer sum{L}(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : sum(a, lo, hi - 1) + a[hi - 1];
*/

/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;
  assigns i, j;
  ensures \forall integer k; leftElement <= k <= rightElement ==> (a[k] != k ==> \result > k);
  ensures \result > rightElement || \result == leftElement || (\exists integer k; leftElement <= k <= rightElement && a[k] == k && \result == k + 1);
*/
int foo197(int * a, int a_len, int leftElement, int rightElement) {

    int i = leftElement;
    int j = rightElement;

    /*@
      loop invariant (\at(leftElement,Pre) <= \at(rightElement,Pre)) ==> (((j == \at(rightElement,Pre))&&(i == \at(leftElement,Pre))&&(rightElement == \at(rightElement,Pre))&&(leftElement == \at(leftElement,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (i >= leftElement && i <= j));
      loop invariant (\at(leftElement,Pre) <= \at(rightElement,Pre)) ==> (((j == \at(rightElement,Pre))&&(i == \at(leftElement,Pre))&&(rightElement == \at(rightElement,Pre))&&(leftElement == \at(leftElement,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (j >= i && j <= rightElement));
      loop invariant (!(\at(leftElement,Pre) <= \at(rightElement,Pre))) ==> ((j == \at(rightElement,Pre))&&(i == \at(leftElement,Pre))&&(rightElement == \at(rightElement,Pre))&&(leftElement == \at(leftElement,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre)));
      loop invariant rightElement == \at(rightElement,Pre);
      loop invariant leftElement == \at(leftElement,Pre);
      loop invariant a_len == \at(a_len,Pre);
      loop invariant a == \at(a,Pre);
      loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k],Pre);
      loop invariant \forall integer k; leftElement <= k < i ==> a[k] != k;
      loop invariant \forall integer k; j < k <= rightElement ==> a[k] != k;
      loop assigns mid, i, j;
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
