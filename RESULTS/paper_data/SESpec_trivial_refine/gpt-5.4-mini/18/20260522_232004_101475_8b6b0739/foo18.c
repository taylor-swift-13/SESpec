
/*@
  requires a_len >= 0;
  requires \valid(a + (0 .. a_len - 1));
  assigns a[0 .. a_len - 1];
  ensures \true;
*/
void foo18(int * a, int a_len) {

    int N = a_len;

    /*@
      loop invariant 1 <= i <= N + 1;
      loop assigns i, a[0 .. N - 1];
      loop variant N - i + 1;
    */
    for (int i = 1; i < N; i++) {
      int j = i - 1;
      int x = a[i];

      /*@
        loop invariant -1 <= j < i;
        loop assigns j, a[0 .. i];
        loop variant j + 1;
      */
      while ((j >= 0) && (a[j] > x)) {
        a[j + 1] = a[j];
        j--;
      }

      a[j + 1] = x;
    }
}
