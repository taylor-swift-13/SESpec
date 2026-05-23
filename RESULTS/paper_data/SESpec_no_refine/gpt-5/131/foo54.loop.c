
/*@
  logic integer max_prefix{L}(int* a, integer i) =
    i == 0 ? a[0] : (max_prefix(a, i - 1) >= a[i] ? max_prefix(a, i - 1) : a[i]);
*/

/*@
  requires \valid_read(a + (0..a_len-1));
  assigns \nothing;
*/
int foo54(int * a, int a_len) {

        if (a_len == 0) return -1;
        int res = -2147483648;
        
        /*@
          loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
          loop assigns i, res;
        */
        for(int i = 0; i < a_len; i++) {
            res = ((a[i] > res) ? a[i] : res);
        }
            
        return res;
}
