
/*@
  requires (m == \at(m,Pre)) && (n == \at(n,Pre));
*/
int foo385(int n, int m) {

    /*@
      loop invariant i <= \at(n,Pre);
      loop invariant i >= (\at(n,Pre) < 0 ? \at(n,Pre) : -1);
      loop invariant \forall integer k; i < k && k <= \at(n,Pre) ==> (k % \at(m,Pre) != 0);
      loop invariant \forall integer k1, k2; i < k1 <= k2 && k2 <= \at(n,Pre) ==>
                     ((k1 % \at(m,Pre) != 0) ==> (k2 % \at(m,Pre) != 0));
      loop invariant (i < 0) ==> (\forall integer k; 0 <= k && k <= \at(n,Pre) ==>
                                  (k % \at(m,Pre) != 0));
      loop invariant m == \at(m,Pre);
      loop invariant n == \at(n,Pre);
      loop invariant (i >= 0) ==> (\forall integer k; i < k && k <= \at(n,Pre) ==>
                                   (k % \at(m,Pre) != 0));
      loop assigns i;
    */
    for (int i = n; i >= 0; i--) {
        if (i % m == 0) {
            return i;
        }
    }

    return -1;
}
