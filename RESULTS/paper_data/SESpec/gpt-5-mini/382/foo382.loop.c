
/*@
  requires \true;
*/
        
int foo382(int n, int x, int y) {

    int max = 0;
        
    /*@
      loop invariant (max == 0) || (1 <= max && max <= i-1);
      loop invariant (\forall integer k; 1 <= k && k <= i-1 ==> ((k % x == y) ==> (max >= k)));
      loop invariant (\forall integer k; 1 <= k && k <= i-1 ==> ((max == k) ==> (k % x == y)));
      loop invariant (\exists integer k; 1 <= k && k <= i-1 && (k % x == y)) ==> (max != 0);
      loop invariant (\forall integer k; 1 <= k && k <= i-1 ==> (max >= k) || (k % x != y));
      loop invariant (\forall integer k; i <= k && k <= \at(n,Pre) ==> ((k % x == y) ==> (k > max)));
      loop invariant (\at(n,Pre) >= 0) ==> ((i <= \at(n,Pre)) ==> (1 <= i));
      loop invariant (i <= \at(n,Pre)) ==> (max <= \at(n,Pre));
      loop invariant (i <= \at(n,Pre)) ==> ((max == 0) || (max % x == y));
      loop invariant (i <= \at(n,Pre)) ==> (((max == 0) && (y == \at(y,Pre)) && (x == \at(x,Pre)) && (n == \at(n,Pre))) || (max >= 1 && max <= \at(n,Pre) && (max % x == y)));
      loop invariant y == \at(y,Pre);
      loop invariant x == \at(x,Pre);
      loop invariant n == \at(n,Pre);
      loop assigns i, max;
    */
    for (int i = 1; i <= n; i++) {
        if ((i % x) == y) {
            max = i;
        }
    }
            
    return max;
}
