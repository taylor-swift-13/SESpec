
/*@
  requires a_len >= 0;
  requires b_len >= 0;
  requires a_len == b_len;
  requires \valid_read(a + (0..a_len-1));
  requires \valid_read(b + (0..b_len-1));
  assigns \nothing;
  ensures (\result == 1) <==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]);
  ensures \result == 0 ==> (\exists integer k; 0 <= k < a_len && a[k] != b[k]) || a_len != b_len;
  ensures \result == 0 || \result == 1;
  ensures a_len == b_len ==> (\result == 0 <==> (\exists integer k; 0 <= k < a_len && a[k] != b[k]));
  ensures a_len == b_len ==> (\result == 1 ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
  ensures \result == 1 ==> a_len == b_len;
  ensures \result == 0 ==> (a_len != b_len || (\exists integer k; 0 <= k < a_len && a[k] != b[k]));
  ensures \result == 1 ==> (\forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre) && b[k] == \at(b[k], Pre));
*/
int foo95(int * a, int a_len, int * b, int b_len) {

        if(a_len != b_len) {
	    return 0;
        }

        /* >>> LOOP INVARIANT TO FILL <<< */
        /*@
          loop invariant 0 <= i <= a_len;
          loop invariant a_len == b_len;
          loop invariant \valid_read(a + (0..a_len-1));
          loop invariant \valid_read(b + (0..b_len-1));
          loop invariant \forall integer k; 0 <= k < i ==> a[k] == b[k];
          loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
          loop invariant \forall integer k; 0 <= k < b_len ==> b[k] == \at(b[k], Pre);
          loop invariant (!(i < a_len)) ==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]);
          loop assigns i;
        */
        for(int i = 0; i < a_len; i++) {
            if(a[i] != b[i]) {
                return 0;
            }
        }

        return 1;
}
