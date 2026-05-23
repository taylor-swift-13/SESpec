
/*@
  logic integer min_prefix{L}(int *a, integer n) =
    n <= 0 ? 2147483647
           : (min_prefix(a, n-1) < a[n-1] ? min_prefix(a, n-1) : a[n-1]);
*/

/*@
  requires \valid_read(a + (0 .. a_len-1));
  requires a_len >= 0;
  ensures \result == (a_len == 0 ? -1 : min_prefix(a, a_len));
  ensures \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
*/
int foo55(int * a, int a_len) {

        if (a_len == 0) return -1;
        int res = 2147483647;
        
        /*@
          loop invariant 0 <= i <= a_len;
          loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
          loop invariant res == min_prefix(a, i);
          loop assigns i, res;
        */
        for(int i = 0; i < a_len; i++) {
            res = ((a[i] < res) ? a[i] : res);
        }
            
        return res;
}
