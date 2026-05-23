
/*@
  requires a_len >= 0;
  requires b_len == a_len;
  requires \valid_read(a + (0 .. a_len - 1));
  requires \valid_read(b + (0 .. b_len - 1));
*/
int foo95(int * a, int a_len, int * b, int b_len) {

        if(a_len != b_len) {
	    return 0;
        }

        
            
        /*@
          loop invariant 0 <= i <= a_len;
          loop invariant b_len == a_len;
          loop invariant \forall integer k; 0 <= k < i ==> a[k] == b[k];
          loop invariant \forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre);
          loop invariant \forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre);
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
