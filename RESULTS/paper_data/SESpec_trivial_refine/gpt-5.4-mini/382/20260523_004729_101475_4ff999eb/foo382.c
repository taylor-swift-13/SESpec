
/*@
  predicate is_match(integer j, integer x, integer y) = (j % x) == y;
*/

/*@
  requires x != 0;
  requires 0 <= n;
  assigns \nothing;
  ensures 0 <= \result;
  ensures \result <= n;
  ensures \result == 0 <==> (\forall integer k; 1 <= k <= n ==> !is_match(k, x, y));
  ensures \result != 0 ==> is_match(\result, x, y);
  ensures \result != 0 ==> (\forall integer k; 1 <= k <= n && is_match(k, x, y) ==> k <= \result);
*/
int foo382(int n, int x, int y) {

    int max = 0;

    /*@
      loop invariant 1 <= i <= n + 1;
      loop invariant 0 <= max <= i - 1;
      loop invariant max == 0 || is_match(max, x, y);
      loop invariant max == 0 ==> (\forall integer k; 1 <= k < i ==> !is_match(k, x, y));
      loop invariant max != 0 ==> (\forall integer k; 1 <= k < i && is_match(k, x, y) ==> k <= max);
      loop assigns i, max;
      loop variant n - i + 1;
    */
    for (int i = 1; i <= n; i++) {
        if ((i % x) == y) {
            max = i;
        }
    }

    return max;
}
