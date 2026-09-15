
/*@
  logic integer cat_sum{L}(int* a, integer lo, integer hi) =
    lo >= hi ? 0 : cat_sum(a, lo, hi - 1) + a[hi - 1];
*/

int foo214(int num) {

    int *catalan = (int *)malloc(sizeof(int) * (num + 1));
    int catalan_len = num + 1;
    catalan[0] = 1;

    /*@
      loop invariant 1 <= i <= num + 1 || i == 1;
      loop invariant catalan_len == num + 1;
      loop assigns i, catalan[0 .. catalan_len - 1];
    */
    for (int i = 1; i <= num; i++) {
        catalan[i] = 0;

        /*@
          loop invariant 0 <= j <= i;
          loop invariant catalan_len == num + 1;
          loop assigns j, catalan[i];
        */
        for (int j = 0; j < i; j++) {
            catalan[i] += catalan[j] * catalan[i - j - 1];
        }
    }

    return catalan[num];
}
