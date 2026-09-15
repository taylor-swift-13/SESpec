int leftInsertion(int * a, int a_len, int x);

/*@ 
  requires a_len >= 0;
  requires a_len == 0 || \valid_read(a + (0 .. a_len-1));
  requires \forall integer i, j; 0 <= i <= j < a_len ==> a[i] <= a[j];
  // Prevent overflow in (left + right)
  requires a_len <= (INT_MAX + 2) / 2;

  assigns \nothing;

  behavior found:
    assumes \exists integer i; 0 <= i < a_len && a[i] == x;
    ensures 0 <= \result < a_len;
    ensures a[\result] == x;

  behavior not_found:
    assumes \forall integer i; 0 <= i < a_len ==> a[i] != x;
    ensures 0 <= \result <= a_len;
    ensures \forall integer i; 0 <= i < \result ==> a[i] < x;
    ensures \forall integer i; \result <= i < a_len ==> a[i] > x;

  complete behaviors;
  disjoint behaviors;
*/
int leftInsertion(int * a, int a_len, int x) {

        int left = 0;
        int right = a_len - 1;
        /*@
          loop invariant 0 <= left <= a_len;
          loop invariant -1 <= right < a_len;
          loop invariant \forall integer i; 0 <= i < left ==> a[i] < x;
          loop invariant \forall integer i; right + 1 <= i && i < a_len ==> a[i] > x;
          loop assigns left, right;
          loop variant right - left + 1;
        */
        while (left <= right) {
            int mid = (left + right) / 2;
            /*@ assert left <= mid <= right; */
            /*@ assert 0 <= mid < a_len; */
            /*@ assert \valid_read(a + mid); */
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
