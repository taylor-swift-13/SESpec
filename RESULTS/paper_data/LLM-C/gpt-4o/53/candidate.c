/*@
    ensures \true;
*/
void foo227() {

    int x;
    int y;

    x = 0;

    /*@
        loop invariant 0 <= x <= 99;
        loop assigns x;
        loop variant 99 - x;
    */
    while (x < 99) {
       if (y % 2 == 0)
           x += 10;
       else
           x -= 5;
    }

}
