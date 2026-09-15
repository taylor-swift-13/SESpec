
/*@
  logic integer sum_fourth_powers(integer n) =
    n <= 0 ? 0 : sum_fourth_powers(n - 1) + (2 * n) * (2 * n) * (2 * n) * (2 * n);
*/

/*@
  requires p >= 0;
  assigns \nothing;
  ensures \result == sum_fourth_powers(p);
  ensures p >= 0 ==> \result >= 0;
  ensures p >= 0 ==> \result % 2 == 0;
*/
int foo397(int p) {

        int even = 0;

        /*@
          loop invariant 1 <= c <= p + 1;
          loop invariant p == \at(p,Pre);
          loop invariant even >= 0;
          loop invariant even % 2 == 0;
          loop invariant even == sum_fourth_powers(c - 1);
          loop invariant (c > \at(p,Pre)) ==> (even == sum_fourth_powers(\at(p,Pre)));
          loop invariant (c <= \at(p,Pre)) ==> (even % 2 == 0);
          loop assigns c, even;
        */
        for (int c = 1; c <= p; c++) {
			int tmp = 2 * c;
			even = even + (tmp * tmp * tmp * tmp);
		}

		return even;
}
