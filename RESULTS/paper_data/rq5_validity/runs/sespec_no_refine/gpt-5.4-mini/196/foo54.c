
/*@
  logic integer max_prefix(int *a, integer lo, integer hi) =
    lo >= hi ? (-2147483647 - 1)
             : (max_prefix(a, lo, hi - 1) > a[hi - 1] ? max_prefix(a, lo, hi - 1) : a[hi - 1]);
*/

/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;
  assigns \nothing;
  ensures \result == max_prefix(a, 0, a_len);
  ensures \result >= 0;
*/
int foo54(int * a, int a_len) {

        if (a_len == 0) return -1;
        int res = Integer.MIN_VALUE;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= a_len;
          loop invariant res == max_prefix(a, 0, i);
          loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
          loop invariant (!(i < a_len)) ==> ();
          loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
          loop assigns i, res;
            */
            for(int i = 0; i < a_len; i++) {
            res = ((a[i] > res) ? a[i] : res);
        }
            
        return res;
}
