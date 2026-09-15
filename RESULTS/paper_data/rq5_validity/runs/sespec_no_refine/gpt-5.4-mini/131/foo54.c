
/*@
  logic integer array_max(int* a, integer lo, integer hi) =
    lo >= hi ? \min_integer : (lo + 1 >= hi ? a[lo] : ((a[lo] > array_max(a, lo + 1, hi)) ? a[lo] : array_max(a, lo + 1, hi)));
*/

/*@ 
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;
  assigns \nothing;
  ensures \result == array_max(a, 0, a_len);
*/
int foo54(int * a, int a_len) {

        if (a_len == 0) return -1;
        int res = Integer.MIN_VALUE;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= a_len;
          loop invariant res == array_max(a, 0, i);
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
