
/*@
  requires n >= 0;
  requires x > 0;
  requires y >= 0 && y < x;
  
  ensures \result == 0 || (\result % x == y && \result <= n);
  ensures \result == 0 ==> \forall integer k; 1 <= k <= n ==> k % x != y;
  ensures \result != 0 ==> (\result % x == y && \result <= n && \forall integer k; 1 <= k <= n ==> (k % x == y ==> k <= \result));
*/
int foo382(int n, int x, int y) {

    int max = 0;

    /*@
      loop invariant 1 <= i <= n + 1;
      loop invariant max == 0 || (max % x == y && max <= i - 1);
      loop invariant \forall integer k; 1 <= k < i ==> (k % x == y ==> max >= k);
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
