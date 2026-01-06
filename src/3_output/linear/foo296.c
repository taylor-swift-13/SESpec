
void foo296() {
    unsigned int x;
    unsigned int y;

    x = 0;
    y = 0;

    /*@
      loop invariant x <= 1000000;
      loop invariant (x <= 500000 ==> y == x) && 
                     (x > 500000 ==> y == 1000000 - x);
      loop assigns x, y;
    */
    while (x < 1000000) {
        if (x < 500000) {
            y++;
        }
        else {
            y--;
        }
        x++;
    }

    /*@ assert y == 0; */
}
