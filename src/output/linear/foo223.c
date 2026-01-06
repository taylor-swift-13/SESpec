
void foo223() {
    int x;
    x = 0;

    /*@ loop invariant x == 0 || x >= 2;
        loop invariant x % 2 == 0;
        loop assigns x;
    */
    while(unknown()) {
        x = x + 2;
    }

    /*@ assert x % 2 == 0; */
}
