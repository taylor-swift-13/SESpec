
/*@
    requires y > 2;
    */
    
void foo232(unsigned int y) {
    unsigned int x;

    x = 2;
            
    /*@
      loop invariant 2 <= x <= y;
      loop invariant (x < y / x) ==> (x * x <= y);
      loop assigns x;
    */
    while (x < y) {
        if (x < y / x) {
            x *= x;
        }
        else {
            x++;
        }
    }

    /*@ assert x == y; */
}
