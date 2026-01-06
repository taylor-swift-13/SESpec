
/*@
    requires x >= y  && y >= 0;
    */
    
void foo79(int x, int y) {

    int i = 0;
    
    /*@
        loop invariant 0 <= i <= x;
        loop invariant y == \at(y,Pre);
        loop invariant x == \at(x,Pre);
        loop assigns i;
    */
    while (unknown()) {
        if (i < y) {
            i = (i + 1);
        }
    }
  
    /*@ assert (i < 0 && i >= x) ==> (i >= y); */
}
