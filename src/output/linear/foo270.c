
/*@
    requires y >= 0;
    */
    
void foo270(int y) {
    int x;
    x = y;

    /*@
    loop invariant (\at(y,Pre) != 0) ==> (y == x);
    loop invariant (\at(y,Pre) != 0) ==> (x >= 0 && y >= 0);
    loop invariant (!(\at(y,Pre) != 0)) ==> ((x == \at(y,Pre))&&(y == \at(y,Pre)));
    loop assigns x, y;
    */
    while (x != 0) {
       x = x - 1;
       y = y - 1;
    }
    
    /*@ assert y == 0; */
}
