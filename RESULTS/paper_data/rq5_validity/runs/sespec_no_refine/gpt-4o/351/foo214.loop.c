
/*@
  predicate undef_data_at(int *p) = \true;
*/

/*@
  requires undef_data_at(&y) * (x == 0);
*/
void foo214() {

    int x;
    int y;

    x = 0;

    /*@
      loop invariant 0 <= x <= 99;
      loop invariant x % 2 == 0 || x % 2 == 1; // x is always an integer
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
