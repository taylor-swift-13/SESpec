
void foo260() {
    int x;
    x = 0;

    /*@
      loop invariant (x == 0) || (x == 1);
      loop assigns x;
    */
    while (unknown()) {
        if(x == 0) {
            x = 1;
        }
    }

    /*@ assert x <= 1; */
}
