
/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  assigns a[0..a_len-1];
  ensures a == \at(a,Pre);
  ensures a_len == \at(a_len,Pre);
  ensures \forall integer i; \forall integer j; 0 <= i <= j < a_len ==> a[i] <= a[j];
*/
void foo18(int * a, int a_len) {

    int N = a_len;
    
    /*@
      loop invariant N == \at(a_len,Pre);
      loop invariant a_len == \at(a_len,Pre);
      loop invariant a == \at(a,Pre);
      loop assigns a[0..N-1];
    */
    for (int i = 1; i < N; i++) {
      int j = i - 1;
      int x = a[i];

      /*@
        loop invariant 0 <= j + 1 <= i;
        loop assigns a[0..N-1], j;
      */
      while ((j >= 0) && (a[j] > x)) {
        a[j + 1] = a[j];
        j--;
      }
      a[j + 1] = x;
    }
}
