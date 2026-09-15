void sort(int * a, int a_len);

/*@
    requires a_len >= 0;
    requires \valid(a + (0 .. a_len - 1));
    assigns a[0 .. a_len - 1];
    ensures \forall integer i, j; 0 <= i <= j < a_len ==> a[i] <= a[j];
    ensures \forall integer v;
        (\sum integer k = 0; k < a_len; k++ ; (\old(a[k]) == v ? 1 : 0))
        == 
        (\sum integer k = 0; k < a_len; k++ ; (a[k] == v ? 1 : 0));
*/
void sort(int * a, int a_len) {

    int N = a_len;
    for (int i = 1; i < N; i++) { // N branches
      int j = i - 1;
      int x = a[i];

      while ((j >= 0) && (a[j] > x)) {
        a[j + 1] = a[j];
        j--;
      }
      a[j + 1] = x;
    }
}
