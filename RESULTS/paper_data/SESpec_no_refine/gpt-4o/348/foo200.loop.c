
/*@
  logic integer count_non_divisible(int l, int r, int a) =
    \sum(l <= i <= r, i % a != 0);
*/

/*@
  requires (count == 0) * (r == \at(r,Pre)) * (l == \at(l,Pre)) * (n == \at(n,Pre)) * (a == \at(a,Pre));
*/
int foo200(int a, int n, int l, int r) {

    int count = 0;

    /*@
      loop invariant l <= i <= r + 1;
      loop invariant count == count_non_divisible(l, i - 1, a);
      loop invariant (i <= \at(r,Pre)) ==> (count == count_non_divisible(l, i - 1, a));
      loop invariant (!(i <= \at(r,Pre))) ==> ((count == 0)&&(r == \at(r,Pre))&&(l == \at(l,Pre))&&(n == \at(n,Pre))&&(a == \at(a,Pre)));
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
