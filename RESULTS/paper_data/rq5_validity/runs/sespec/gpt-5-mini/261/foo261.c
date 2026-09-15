
/*@
  requires \valid_read(a + (0 .. a_len-1));
  requires a_len >= 0;
  requires \forall integer p; 0 <= p < a_len-1 ==> a[p] < a[p+1];
  assigns \nothing;
  ensures 0 <= \result <= a_len;
  ensures (\exists integer k; 0 <= k < a_len && a[k] == x) <==> (\result < a_len && a[\result] == x);
  ensures (\result < a_len) ==> a[\result] == x;
  ensures ((\forall integer k; 0 <= k < \result ==> a[k] < x) && (\forall integer k; \result <= k && k < a_len ==> a[k] > x)) || (\result < a_len && a[\result] == x);
*/
int foo261(int * a, int a_len, int x) {

        int i = 0;
        int j = a_len - 1;
        
        /*@
          loop invariant 0 <= i <= a_len;
          loop invariant -1 <= j <= a_len - 1;
          loop invariant i <= j + 1;
          loop invariant i == 0 || a[i-1] < x;
          loop invariant j == a_len-1 || a[j+1] > x;
          loop assigns \nothing;
        */
        while (i <= j) {
            int mid = (i + j) / 2;
            if (a[mid] == x) {
                return mid;
            } else if (a[mid] < x) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
            
        return i;
}
