
/*@
    requires x == y && x >= 0 && x + y + z == 0;
    */
    
void foo286(int x, int y, int z) {
    
    /*@
        loop invariant (\at(x,Pre) > 0) ==> (x == \at(x,Pre) - \at(x,Pre) + x && x >= 0 && x + y + z == 0);
        loop invariant (\at(x,Pre) > 0) ==> (y == \at(y,Pre) - \at(y,Pre) + y && y == x);
        loop invariant (\at(x,Pre) > 0) ==> (z == \at(z,Pre) + 2*(\at(x,Pre) - x));
        loop invariant (!(\at(x,Pre) > 0)) ==> ((z == \at(z,Pre))&&(y == \at(y,Pre))&&(x == \at(x,Pre)));
        loop assigns x, y, z;
    */
    while (x > 0) {
       x--;
       y--;
       z += 2;
    }
            
    /*@ assert z <= 0; */
}
