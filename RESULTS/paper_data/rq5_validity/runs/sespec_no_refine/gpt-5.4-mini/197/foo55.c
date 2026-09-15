
/*@ 
  logic integer array_min(int *a, integer lo, integer hi) =
    lo >= hi ? 2147483647
             : ((a[hi - 1] < array_min(a, lo, hi - 1)) ? a[hi - 1] : array_min(a, lo, hi - 1));
*/

/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;
  assigns res;
  ensures \result == array_min(a, 0, a_len);
*/
int foo55(int * a, int a_len) {

        if (a_len == 0) return -1;
        int res = Integer.MIN_VALUE;
        
            
        /*@
          loop invariant 0 <= i <= a_len;
          loop invariant res <= a[i - 1] || i == 0;
          loop invariant res == array_min(a, 0, i) || i == 0;
          loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
          loop assigns i, res;
            */
            for(int i = 0; i < a_len; i++) {
            res = ((a[i] < res) ? a[i] : res);
        }
            
        return res;
}
