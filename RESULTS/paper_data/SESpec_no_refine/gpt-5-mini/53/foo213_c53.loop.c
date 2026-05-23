
/*@ predicate undef_data_at(int *p) = \true; */

void foo213_c53() {

    int x;
    int y;

    x = 0;

    /*@
      loop invariant x % 5 == 0;              // modular invariant preserved by +/-10 and -5
      loop assigns x;
    */
    while (x < 99) {
       if (y % 2 == 0)
         x += 10;
       else
         x -= 5;
    }

}
