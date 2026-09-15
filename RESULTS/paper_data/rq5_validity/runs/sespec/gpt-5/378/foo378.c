
/*@
  logic integer odd_sum_from_to(integer a, integer b) =
    (a > b) ? 0 :
    ((a % 2 != 0) ? a : 0) + odd_sum_from_to(a + 1, b);
*/

/*@
  assigns \nothing;
  ensures (l > r) ==> (\result == 0);
  ensures (l > r) ==> (odd_sum_from_to(l, r) == 0) ;
*/
int foo378(int l, int r) {

        int sum = 0;

            /*@
          loop invariant l == \at(l,Pre);
          loop invariant r == \at(r,Pre);

          loop invariant (l <= r) ==> (l <= i <= r + 1);
          loop invariant (l > r) ==> (i == l);
          loop invariant (l > r) ==> (sum == 0);

          loop invariant (i == l) ==> (sum == 0);

          loop invariant (i <= \at(r,Pre) + 1) ==> (l <= i <= r + 1);
          loop invariant (!(i <= \at(r,Pre))) ==> ((r == \at(r,Pre))&&(l == \at(l,Pre)));
          loop invariant r == \at(r,Pre);
          loop invariant l == \at(l,Pre);
          loop assigns i, sum;
            */
            for (int i = l; i <= r; i++) {
            if (i % 2 != 0) {
                sum += i;
            }
        }

        return sum;
}
