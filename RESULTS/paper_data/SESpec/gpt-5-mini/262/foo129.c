
/*@
  /* Predicate expressing that array a is equal to its value in the pre-state */
  logic boolean same_array(int* a, integer lo, integer hi, int* a_pre) =
    \forall integer i; lo <= i < hi ==> a[i] == a_pre[i];
*/

/*@ 
  predicate same_array(int* a, integer lo, integer hi, int* a_pre) =
    \forall integer i; lo <= i < hi ==> a[i] == a_pre[i];
*/
/*@
  requires a_len > 0;
  requires a_len < 100;
  requires \valid(a + (0 .. a_len - 1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  assigns \nothing;
  ensures 0 <= \result <= a_len;
  ensures \result < a_len ==> a[\result] == x;
  ensures \result == a_len ==> \forall integer i; 0 <= i < a_len ==> a[i] != x;
*/
int foo129(int * a, int a_len, int x) {

    int left = 0;
    int right = a_len - 1;
    
    /*@
      loop invariant 0 <= left && left <= a_len;
      loop invariant -1 <= right && right < a_len;
      loop invariant left <= right + 1;
      loop invariant \forall integer i; 0 <= i < left ==> a[i] < x;
      loop invariant \forall integer i; right < i < a_len ==> a[i] > x;
      loop assigns left, right, \from a[*];
      loop variant right - left + 1;
    */
    while (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] == x) {
            return mid;
        } else if (a[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
        
    return left;
}
