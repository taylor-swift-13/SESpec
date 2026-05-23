
/*@
  predicate undef_data_at(int *p) = \true;
*/

void foo214() {

    int x;
    int y;

    x = 0;

    /*@
      loop invariant (y % 2 == 0) ==> (x % 2 == 0);
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
