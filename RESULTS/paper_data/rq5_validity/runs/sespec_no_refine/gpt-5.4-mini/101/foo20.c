
/*@
  logic integer copied_count(int *b, int *a, integer lo, integer hi) =
    lo >= hi ? 0
              : copied_count(b, a, lo, hi - 1) + (a[hi - 1] == b[hi - 1] ? 1 : 0);
*/

/*@ 
        logic integer PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */

/*@ logic integer foo20_copied_count_total(int *b, int *a, int lo, int hi) = copied_count(b, a, lo, hi); */
/*@
  requires \valid(&b[0] + (0..b_len-1));
  requires \forall integer i; 0 <= i < b_len ==> 0 <= b[i] <= 100;
  requires b_len > 0;
  requires b_len < 100;
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;
  assigns a[0 .. a_len - 1], k;
  ensures iEnd - iBegin <= 0 ==> \result == 0;
  ensures iEnd - iBegin > 0 ==> (\forall integer t; iBegin <= t < iEnd ==> a[t] == b[t]);
  ensures iEnd - iBegin > 0 ==> copied_count(b, a, iBegin, iEnd) == iEnd - iBegin;
*/
void foo20(int * b, int b_len, int iBegin, int iEnd, int * a, int a_len) {

        int k = iBegin;

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (\at(iEnd,Pre) - \at(iBegin,Pre) > 0) ==> (k >= \at(iBegin,Pre) && k <= \at(iEnd,Pre) && copied_count(b, a, \at(iBegin,Pre), k) == k - \at(iBegin,Pre)) ;
          loop invariant (!(\at(iEnd,Pre) - \at(iBegin,Pre) > 0)) ==> ((k == \at(iBegin,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))&&(iEnd == \at(iEnd,Pre))&&(iBegin == \at(iBegin,Pre))&&(b_len == \at(b_len,Pre))&&(b == \at(b,Pre)));
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant iEnd == \at(iEnd,Pre);
          loop invariant iBegin == \at(iBegin,Pre);
          loop invariant b_len == \at(b_len,Pre);
          loop invariant b == \at(b,Pre);
          loop invariant \forall integer t; \at(iBegin,Pre) <= t < k ==> a[t] == b[t];
          loop invariant \forall integer t; k <= t < \at(iEnd,Pre) ==> a[t] == \at(a[t], Pre);
          loop assigns a[..], k;
            */
            while (iEnd - k > 0) {
            a[k] = b[k];
            k = k + 1 ;
        }
            
}
