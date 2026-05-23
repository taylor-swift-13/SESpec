
/*@ axiomatic EvenSum {
  logic integer even_sum(integer l, integer r);

  axiom even_sum_empty:
    \forall integer l, r; l > r ==> even_sum(l, r) == 0;

  axiom even_sum_odd:
    \forall integer l, r; l <= r && r % 2 != 0 ==> even_sum(l, r) == even_sum(l, r - 1);

  axiom even_sum_even:
    \forall integer l, r; l <= r && r % 2 == 0 ==> even_sum(l, r) == even_sum(l, r - 1) + r;
} */

/*@ 
  requires l <= r + 1;
  assigns \nothing;
  ensures \result == even_sum(l, r);
*/
int foo379(int l, int r) {
    int sum = 0;

    /*@
      loop invariant l <= i <= r + 1;
      loop invariant sum == even_sum(l, i - 1);
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
