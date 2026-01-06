
void foo257() {
    int x;
    x = 40;

    /*@ loop invariant 0 <= x <= 40;
        loop assigns x;
    */
    while (x != 0) {
        x = x - 1;
    }

    /*@ assert x == 0; */
}
