
/*@ 
  logic integer cnt_not_div(integer L, integer I, integer A) =
    L >= I ? 0 : ((L % A != 0) ? 1 : 0) + cnt_not_div(L+1, I, A);
*/

int foo348(int a, int n, int l, int r) {

    int count = 0;
        
    /*@
      loop invariant i >= l;
      loop invariant 0 <= count;
      loop invariant count <= i - l;
      loop invariant (count > 0) ==> (\exists integer k; l <= k < i && k % a != 0);
      loop invariant r == \at(r,Pre);
      loop invariant l == \at(l,Pre);
      loop invariant n == \at(n,Pre);
      loop invariant a == \at(a,Pre);
      loop assigns i, count;
    */
    for (int i = l; i <= r; i++) {
        if (i % a != 0) {
            count++;
        }
        if (count == n) {
            return i;
        }
    }
            
    /*@ assert count < n; */
    return -1;
}
