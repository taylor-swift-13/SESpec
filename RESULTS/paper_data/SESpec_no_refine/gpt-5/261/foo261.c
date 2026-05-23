
/*@
  // No additional predicates or logic functions are required for this loop.
*/

/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;
  assigns \nothing;   
  ensures 0 <= \result <= a_len;
  ensures \result == (\exists integer k; 0 <= k < a_len && a[k] == x) ? (\exists integer k; 0 <= k < a_len && a[k] == x && \result == k) : \result == (\let r = \min \integer i; 0 <= i <= a_len && (\forall integer t; 0 <= t < i ==> a[t] < x) && (i == a_len || a[i] >= x) in r);
  ensures \result == (\exists integer k; 0 <= k < a_len && a[k] == x) ? \result : (\forall integer t; 0 <= t < \result ==> a[t] < x) && (\result == a_len || a[\result] >= x);
  ensures \result == PLACE_HOLDER_RESULT;  
*/
int foo261(int * a, int a_len, int x) {

        int i = 0;
        int j = a_len - 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant -1 <= j < a_len;
              loop invariant 0 <= i <= j + 1;
              loop invariant a_len == \at(a_len,Pre);
              loop invariant x == \at(x,Pre);
              loop invariant a == \at(a,Pre);
              loop assigns i, j;
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
