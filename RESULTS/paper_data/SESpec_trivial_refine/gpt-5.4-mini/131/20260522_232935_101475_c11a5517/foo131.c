
        /*@
        */

/*@
  requires 0 <= a_len;
  requires a_len == 0 || \valid_read(a + (0 .. a_len-1));
  assigns \nothing;
  ensures a_len == 0 ==> \result == -1;
  ensures a_len > 0 ==> \forall integer j; 0 <= j < a_len ==> \result >= a[j];
  ensures a_len > 0 ==> \exists integer j; 0 <= j < a_len && \result == a[j];
  ensures a_len > 0 ==> \result >= INT_MIN;
*/
int foo131(int * a, int a_len) {

        if (a_len == 0) return -1;
        int res = INT_MIN;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= a_len;
          loop invariant \forall integer j; 0 <= j < i ==> a[j] <= res;
          loop invariant res >= INT_MIN;
          loop assigns i, res;
            */
            for(int i = 0; i < a_len; i++) {
            res = ((a[i] > res) ? a[i] : res);
        }
            
        return res;
}
