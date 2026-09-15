
/*@
  requires a_len >= 0;
  assigns \nothing;
*/

void foo18(int * a, int a_len) {

    int N = a_len;
    for (int i = 1; i < N; i++) { // N branches
      int j = i - 1;
      int x = a[i];

      /*@ 
        loop invariant -1 <= j <= i - 1;
        loop invariant x == \old(a[i]);
        loop invariant \forall integer k; j+1 <= k <= i ==> a[k] >= x;
        loop assigns a[..], j;
      */
      while ((j >= 0) && (a[j] > x)) {
        a[j + 1] = a[j];
        j--;
      }
      a[j + 1] = x;
    }
}
