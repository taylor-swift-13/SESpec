
void foo161() {
    int x;
    int y;
    int i;
    int j;

    x = i;
    y = j;

    /*@
      loop invariant y - x == j - i;
      loop invariant (x == 0) ==> (y == j - i);
      loop assigns x, y;
    */
    while(x != 0) {
       x = x - 1;
       y = y - 1;
    }

    /*@ assert (y != 0) ==> (i != j); */
}
