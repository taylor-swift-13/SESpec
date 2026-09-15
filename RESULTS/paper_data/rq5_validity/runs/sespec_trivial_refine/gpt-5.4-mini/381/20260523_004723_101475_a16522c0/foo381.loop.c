
int foo381(int x, int y) {

    int count = 0;

    /*@
      loop invariant 1 <= i;
      loop invariant 0 <= count;
      loop invariant count <= i - 1;
      loop assigns count, i;
    */
    for (int i = 1; i <= x && i <= y; i++) {
        if (x % i == 0 && y % i == 0) {
            count++;
        }
    }

    return count;
}
