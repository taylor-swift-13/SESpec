
void foo150() {
    int x;
    int y;

    x = 0;
    y = 0;

    /*@
      loop invariant x >= 0;
      loop invariant (x <= 4 ==> y == 100 * x) && 
                     (x > 4 ==> y == 400 + (x - 4));
      loop assigns x, y;
    */
    while(unknown()) {
       if(x >= 4) {
           x = x + 1;
           y = y + 1;
       }
       else if(x < 0) {
           y = y - 1;
       }
       else {
           x = x + 1;
           y = y + 100;
       }
    }

    /*@ assert (y <= 2) ==> (x < 4); */
}
