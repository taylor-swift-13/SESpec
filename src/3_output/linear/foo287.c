
/*@
    requires x < 100 && y < 100;
    */
    
void foo287(int x, int y) {
    
    /*@
        loop invariant (\at(x,Pre) < 100 && \at(y,Pre) < 100) ==> (x == \at(x,Pre) + (\at(x,Here) - \at(x,Pre)) && x <= 100);
        loop invariant (\at(x,Pre) < 100 && \at(y,Pre) < 100) ==> (y == \at(y,Pre) + (\at(y,Here) - \at(y,Pre)) && y <= 100);
        loop invariant (!(\at(x,Pre) < 100 && \at(y,Pre) < 100)) ==> ((y == \at(y,Pre))&&(x == \at(x,Pre)));
        loop assigns x, y;
    */
    while (x < 100 && y < 100) {
       x = x + 1;
       y = y + 1;
    }
            
    /*@ assert x == 100 || y == 100; */
}
