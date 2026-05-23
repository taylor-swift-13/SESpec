
/*@
  predicate undef_data_at(int *p) = \true;
*/

/*@
  predicate even(int n) = n % 2 == 0;
  predicate odd(int n) = n % 2 != 0;
*/

void foo214() {

    int x;
    int y;

    x = 0;

    /*@
      loop invariant 0 <= x <= 99;
      loop invariant \forall integer k; 0 <= k < x ==> (even(k) || odd(k));
      loop assigns x;
    */
    while (x < 99) {
        if (y % 2 == 0) {
            x = x + 2;
        } else {
            x = x + 1;
        }
    }
}
