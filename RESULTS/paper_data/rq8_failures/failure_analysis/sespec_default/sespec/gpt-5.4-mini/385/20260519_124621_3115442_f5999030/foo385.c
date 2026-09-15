
/*@ 
  assigns \nothing;
  ensures \result == -1 || (\result >= 0 && \result <= \old(n) && \result % \old(m) == 0);
  
  ensures \result == -1 || \result == \old(n) || \result < \old(n);
*/
int foo385(int n, int m) {

    /*@
      loop invariant m == \at(m,Pre);
      loop invariant n == \at(n,Pre);
      loop invariant i <= n;
      loop invariant (i >= 0) ==> (m == \at(m,Pre) && n == \at(n,Pre));
      loop invariant (!(i >= 0)) ==> ((m == \at(m,Pre)) && (n == \at(n,Pre)));
      loop assigns i;
    */
    for (int i = n; i >= 0; i--) {
        if (i % m == 0) {
            return i;
        }
    }

    return -1;
}
