
/*@
  logic integer count_up_to(integer i, integer l, integer a) =
    (i < l) ? 0 :
    ((i % a != 0) ? 1 : 0) + count_up_to(i - 1, l, a);
*/

int foo200(int a, int n, int l, int r) {

        int count = 0;
        
            
        /*@
          loop invariant (i <= \at(r,Pre)) ==> (count >= 0);
          loop invariant r == \at(r,Pre);
          loop invariant l == \at(l,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant a == \at(a,Pre);
          loop assigns i, count;
            */
            for (int i = l; i <= r; i++) {
            if (i % a != 0) {
                count++;
            }
            if (count == n) {
                return i;
            }
        }
            
        return -1;
}
