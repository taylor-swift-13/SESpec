
/*@
  predicate is_even(integer v) = v % 2 == 0;
*/

void foo53() {

    int x;
    int y;

    x = 0;

    /*@
      loop invariant is_even(y) ==> (0 <= x && x <= 100);
      loop invariant !is_even(y) ==> (x <= 0);
      loop invariant is_even(y) ==> (x % 10 == 0);
      loop invariant x % 5 == 0;
      loop invariant is_even(y) || x <= 0;
      loop invariant !(x < 99) ==> (is_even(y) && x == 100);
      loop invariant x <= 100;
      loop invariant x % 5 == 0;
      loop assigns x;
    */
    while (x < 99) {
       if (y % 2 == 0)
         x += 10;
       else
         x -= 5;
    }

}
