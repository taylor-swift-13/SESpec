
/*@ predicate perm_slice{L1,L2}(int *a, integer l, integer u) =
      \forall integer v; occ_at{L1}(a,l,u,v) == occ_at{L2}(a,l,u,v); */
/*@
  requires a_len >= 0;
  assigns a[0 .. a_len-1];
  ensures a_len <= 1 ==> \true;
  ensures a_len >= 2 ==> (\forall integer i,j; 0 <= i <= j < a_len ==> a[i] <= a[j]);
  ensures perm_slice{Pre,Post}(a, 0, a_len-1);
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
