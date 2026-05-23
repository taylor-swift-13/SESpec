
/*@ axiomatic ProdMod10 {
    logic integer prod_mod10(integer a, integer b);

    axiom prod_mod10_refl:
      \forall integer a; prod_mod10(a, a) == 1;

    axiom prod_mod10_step:
      \forall integer a, b; a < b ==>
        prod_mod10(a, b + 1) == (prod_mod10(a, b) * (b % 10)) % 10;
  }
*/

/*@
  assigns \nothing;

  behavior equal:
    assumes n == c;
    ensures \result == 1;

  behavior decreasing:
    assumes n > c;
    ensures \result == 1;

  behavior large_gap:
    assumes n < c && (c - n) >= 5;
    ensures \result == 0;

  behavior product_increasing:
    assumes n < c && (c - n) < 5;

  complete behaviors;
  disjoint behaviors;
*/
int foo331(int n, int c) {

    int result = 1;

    if (n == c) {
        return 1;
    } else if (n > c) {
        return 1;
    } else if ((c - n) >= 5) {
        return 0;
    } else {
        int index = n + 1;

        /*@
          loop invariant n + 1 <= index;
          loop invariant index <= c + 1;
          loop invariant -9 <= result <= 9;
          loop assigns index, result;
        */
        while (index < c + 1) {
            int old_index = index;
            result = (result * (old_index % 10)) % 10;
            index = old_index + 1;
        }

        return result % 10;
    }
}
