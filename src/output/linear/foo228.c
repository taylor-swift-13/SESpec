
void foo228() {
    int x;
    int y;

    x = 0;

    /*@
      loop invariant (y % 2 == 0) ==> (x % 2 == 0);
      loop invariant (y % 2 != 0) ==> (x % 2 == (x + 1) % 2);
      loop invariant x >= 0 && x <= 100;
      loop assigns x;
    */
    while (x < 99) {
        if (y % 2 == 0) {
            x = x + 2;
        }
        else {
            x = x + 1;
        }
    }

    /*@ assert (x % 2) == (y % 2); */
}
