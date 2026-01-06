
/*@
    requires x >= 0 && x <= 10 && y <= 10 && y >= 0;
*/
    
void foo12(int x, int y, int z1, int z2, int z3) {
/*@
    loop invariant x == \at(x, Pre) + (y - \at(y, Pre));
    loop invariant y == \at(y, Pre) + (x - \at(x, Pre));
    loop invariant x >= \at(x, Pre);
    loop invariant y >= \at(y, Pre);
    loop invariant z3 == \at(z3, Pre);
    loop invariant z2 == \at(z2, Pre);
    loop invariant z1 == \at(z1, Pre);
    loop assigns x, y;
*/
    while (unknown()) {
        x = x + 10;
        y = y + 10;
    }
            
    /*@ assert (y == 0) ==> (x != 20); */  
}
