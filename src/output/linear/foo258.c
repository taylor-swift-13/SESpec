
void foo258() {
    int x;
    x = 0;

    /*@
      loop invariant (x == 0) || (x >= 1 && x <= 41);
      loop assigns x;
    */
    while (unknown()) {
        if(unknown()) {
            x = x + 1;
            if(x > 40) {
                x = 0;
            }
        }
    }
    
    /*@ assert x >= 0; */
}
