
void foo297() {
    int x;
    int y;

    x = 0;
    y = 500000;

    /*@
      loop invariant 0 <= x <= 1000000;
      loop invariant (x <= 500000 ==> y == 500000) && 
                     (x > 500000 ==> y == x);
      loop assigns x, y;
    */
    while(x < 1000000) {
        if (x < 500000) {
            x = x + 1;
        }
        else {
            x = x + 1;
            y = y + 1;
        }
    }

    /*@ assert y == x; */
}
