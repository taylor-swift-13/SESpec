/*@ axiomatic SumEvenRange {
    logic integer sum_even_range(integer l, integer r);

    axiom sum_even_empty:
      \forall integer l, r; l > r ==> sum_even_range(l, r) == 0;

    axiom sum_even_step:
      \forall integer l, r; l <= r ==>
        sum_even_range(l, r) ==
          ((l % 2 == 0 ? l : 0) + sum_even_range(l + 1, r));
  }
*/

int sumEven(int l, int r);

/*@ 
  assigns \nothing;
  ensures \result == sum_even_range(l, r);
*/
int sumEven(int l, int r) {

        int sum = 0;
        /*@
          loop invariant i >= l;
          loop invariant i <= r + 1 || l > r;
          loop invariant sum == sum_even_range(l, i - 1);
          loop assigns i, sum;
          loop variant r - i + 1;
        */
        for (int i = l; i <= r; i++) {
            if (i % 2 == 0) {
                sum += i;
            }
        }
        return sum;
}
