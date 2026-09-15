
/*@ 
  logic integer array_max(int *a, integer lo, integer hi) =
    lo >= hi ? (-2147483648) :
    (lo + 1 >= hi ? a[lo] :
     (a[lo] > array_max(a, lo + 1, hi) ? a[lo] : array_max(a, lo + 1, hi)));
*/
        
int foo54(int * a, int a_len) {

        if (a_len == 0) return -1;
        int res = Integer.MIN_VALUE;
        
            
        /*@
          loop invariant 0 <= i <= a_len;
          loop invariant res == array_max(a, 0, i);
          loop invariant \forall integer k; 0 <= k < i ==> a[k] <= res;
          loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
          loop invariant (!(i < a_len)) ==> ();
          loop invariant PLACE_HOLDER_UNCHANGED_ARRAY_a ;
          loop assigns i, res;
            */
            for(int i = 0; i < a_len; i++) {
            res = ((a[i] > res) ? a[i] : res);
        }
            
        return res;
}
