
void foo160() {
    int x;
    int y;
    int i;
    int j;

    x = i;
    y = j;

    /*@
      loop invariant y == x + (j - i);
      loop assigns x, y;
    */
    while(x != 0) {
       x = x - 1;
       y = y - 1;
    }

    /*@ assert (i == j) ==> (y == 0); */
}
