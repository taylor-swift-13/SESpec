
/*@
predicate sorted_between(int *a, integer l, integer r) =
  \forall integer p, q; l <= p <= q <= r ==> a[p] <= a[q];
*/

/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(a + (0 .. a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;
  assigns a[0 .. a_len-1];
  ensures sorted_between(a, 0, a_len-1)
       && (\forall integer v; 0 <= v <= 100 ==>
             count_eq(a, 0, a_len, v) == count_eq(\at(a,Pre), 0, a_len, v));
*/
void foo18(int * a, int a_len) {

    int N = a_len;
    
    /*@
      loop invariant 1 <= i <= \at(a_len,Pre);
      loop invariant sorted_between(a, 0, i-1);
      loop invariant \forall integer v; 0 <= v <= 100 ==>
                       count_eq(a, 0, \at(a_len,Pre), v) == count_eq(\at(a,Pre), 0, \at(a_len,Pre), v);
      loop assigns a[0 .. \at(a_len,Pre)-1];
    */
    for (int i = 1; i < N; i++) { // N branches
      int j = i - 1;
      int x = a[i];

      /*@
        loop invariant 0 <= j+1 <= i;
        loop invariant sorted_between(a, 0, j);
        loop invariant (\forall integer k; j+1 <= k <= i-1 ==> a[k] > x);
        loop assigns a[0 .. \at(a_len,Pre)-1];
      */
      while ((j >= 0) && (a[j] > x)) {
        a[j + 1] = a[j];
        j--;
      }
            
      a[j + 1] = x;
    }
            
}
