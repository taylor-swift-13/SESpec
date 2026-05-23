
/*@ */
int foo383(int n) {

    int count = 0;

    /* >>> LOOP INVARIANT TO FILL <<< */

    /*@
      loop invariant i >= 1;
      loop invariant 0 <= count <= i - 1;
      loop assigns i, count;
    */
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            count++;
        }
    }

    return count;
}
