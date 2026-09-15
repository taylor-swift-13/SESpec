
int foo348(int a, int n, int l, int r) {

    int count = 0;
    
    /*@
      loop invariant r == \at(r,Pre);
      loop invariant l == \at(l,Pre);
      loop invariant n == \at(n,Pre);
      loop invariant a == \at(a,Pre);
      loop invariant l <= i;
      loop invariant 0 <= count;
      loop invariant count <= i - l;
      loop invariant i == l ==> count == 0;
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
        
    return -1;
}
