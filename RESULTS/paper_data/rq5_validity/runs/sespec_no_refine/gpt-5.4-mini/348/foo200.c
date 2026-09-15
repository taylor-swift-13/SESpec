
/*@ 
  assigns \nothing;
  ensures (\old(a) == 0) || (\result == -1) || (\result >= l && \result <= r);
  ensures (\old(a) == 0) || ((\result != -1) ==> (count_up_to(\result, l, a) == n));
  ensures (\old(a) == 0) || ((\result != -1) ==> (\result == l || count_up_to(\result - 1, l, a) < n));
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
