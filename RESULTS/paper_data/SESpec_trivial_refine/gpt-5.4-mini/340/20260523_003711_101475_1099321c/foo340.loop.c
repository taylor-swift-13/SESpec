
int foo340(int n, int z) {
    if (z < 0) {
        z = -z;
    }
    int result = 0;

    /*@
      loop invariant 1 <= loop;
      loop invariant loop <= z + 1;
      loop invariant 0 <= result;
      loop invariant result <= loop - 1;
      loop assigns result, loop;
    */
    for (int loop = 1; loop <= z; loop++) {
        if (n % loop == 0) {
            result = result + 1;
        }
    }

    return result;
}
