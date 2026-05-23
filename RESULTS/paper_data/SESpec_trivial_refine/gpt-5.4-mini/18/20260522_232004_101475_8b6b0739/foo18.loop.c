
/*@
  requires a_len >= 0;
  requires \valid(a + (0 .. a_len - 1));
*/

void foo18(int * a, int a_len) {

    int N = a_len;

    /*@
      loop invariant 1 <= i <= N;
      loop invariant \forall integer k; 0 <= k < i - 1 ==> a[k] <= a[k + 1];
      loop assigns i, j, x, a[0 .. N - 1];
    */
    for (int i = 1; i < N; i++) { // N branches
      int j = i - 1;
      int x = a[i];

      /* >>> LOOP INVARIANT TO FILL <<< */
      /*@
        loop invariant -1 <= j < i;
        loop invariant 1 <= i <= N;
        loop invariant \forall integer k; j + 1 <= k <= i - 1 ==> a[k] > x;
        loop assigns j, a[0 .. i];
      */
      while ((j >= 0) && (a[j] > x)) {
        a[j + 1] = a[j];
        j--;
      }
            
      a[j + 1] = x;
    }
}
