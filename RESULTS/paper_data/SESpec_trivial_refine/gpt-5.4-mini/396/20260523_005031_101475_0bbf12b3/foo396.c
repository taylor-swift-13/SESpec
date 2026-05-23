
/*@ axiomatic Sum4 {
  logic integer sum4(integer n);

  axiom sum4_base:
    sum4(0) == 0;

  axiom sum4_step:
    \forall integer n; n > 0 ==> sum4(n) == sum4(n - 1) + (2*n)*(2*n)*(2*n)*(2*n);
} */

/*@
assigns \nothing;
behavior nonpositive:
  assumes p <= 0;
  ensures \result == 0;
behavior positive:
  assumes p > 0;
  ensures \result == sum4(p);
complete behaviors;
disjoint behaviors;
*/
int foo396(int p) {
    if (p <= 0) {
        return 0;
    }

    int even = 0;

    /*@
      loop invariant 1 <= c <= p + 1;
      loop invariant even == sum4(c - 1);
      loop assigns c, even;
      loop variant p - c + 1;
    */
    for (int c = 1; c <= p; c++) {
        int count = 2 * c;
        even = even + (count * count * count * count);
    }

    return even;
}
