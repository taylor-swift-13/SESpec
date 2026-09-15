
/*@
  // no extra predicates needed
*/

/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;
  assigns \nothing;   
  ensures (0 <= \result < a_len ==> a[\result] == x) &&
          (a[\result] == x ==> 0 <= \result < a_len) &&
          ((\result < 0 || \result >= a_len) ==> 0 <= \result <= a_len) &&
          (0 <= \result && \result < a_len || 0 <= \result && \result == a_len);
  ensures \result == \result;  
*/
int foo262(int * a, int a_len, int x) {

        int left = 0;
        int right = a_len - 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant a == \at(a,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant x == \at(x,Pre);
          loop invariant -1 <= right <= a_len - 1;
          loop invariant 0 <= left <= a_len;
          loop invariant left <= right + 1;
          loop invariant \valid_read(a + (0 .. a_len - 1));
          loop assigns left, right;
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
