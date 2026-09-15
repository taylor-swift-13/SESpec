
void foo53() {

    int x;
    int y;

    x = 0;

    /*@
      loop invariant x % 5 == 0; // x is always a multiple of 5 due to the loop body
      loop invariant x <= 105; // x cannot exceed 105 due to the loop condition
      loop invariant \exists integer k; x == 5 * k; // x is always a multiple of 5
      loop assigns x;
    */
    while (x < 99) {
        if (y % 2 == 0)
            x += 10;
        else
            x -= 5;
    }
}
