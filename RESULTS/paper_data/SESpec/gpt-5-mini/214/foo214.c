
/*@
  assigns \nothing;
*/
int foo214(int num) {

    int *catalan = (int *)malloc(sizeof(int) * (num + 1));
    int catalan_len = num + 1;
    catalan[0] = 1;

    /*@
      loop invariant 1 <= i <= num + 1 || i == 1;
      loop invariant catalan_len == num + 1;
      loop assigns \nothing;
    */
    for (int i = 1; i <= num; i++) {
        catalan[i] = 0;

        /*@
          loop invariant 0 <= j <= i;
          loop invariant catalan_len == num + 1;
          loop assigns \nothing;
        */
        for (int j = 0; j < i; j++) {
            catalan[i] += catalan[j] * catalan[i - j - 1];
        }
    }

    return catalan[num];
}
