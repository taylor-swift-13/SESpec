
/*@
  logic integer odd_sum_from_to(integer a, integer b) =
    (a > b) ? 0 :
    ((a % 2 != 0) ? a : 0) + odd_sum_from_to(a + 1, b);
*/

/*@
  axiomatic OddSumFromTo_Step {
    lemma odd_sum_from_to_step:
      \forall integer a, b;
        a <= b ==>
          odd_sum_from_to(a, b) ==
            odd_sum_from_to(a, b-1) + ((b % 2 != 0) ? b : 0);

    lemma odd_sum_from_to_empty:
      \forall integer a, b;
        a > b ==> odd_sum_from_to(a, b) == 0;
  }
*/

int foo378(int l, int r) {

        int sum = 0;

            /*@
          loop invariant l == \at(l,Pre);
          loop invariant r == \at(r,Pre);

          loop invariant (l <= r) ==> (l <= i <= r + 1);
          loop invariant (l > r) ==> (i == l);

          loop invariant (l <= r) ==> (sum == odd_sum_from_to(l, i - 1));
          loop invariant (l > r) ==> (sum == 0);

          loop invariant (i == l) ==> (sum == 0);

          loop invariant (i <= \at(r,Pre)) ==> (l <= i <= r);
          loop invariant (i <= \at(r,Pre)) ==> (sum == odd_sum_from_to(l, i - 1)) ;
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
