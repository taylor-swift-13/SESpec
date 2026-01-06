
/*@
    requires x >= 0 && x <= y && y < n;
    */
    
void foo268(int n, int x, int y) {

    /*@
      loop invariant \at(x, LoopEntry) <= x <= n;
      loop invariant \at(y, LoopEntry) <= y <= n;
      loop invariant y >= x - 1;
      loop invariant y >= n - (n - x);
      loop assigns x, y;
    */
    while (x < n) {
       x = x + 1;
       if(x > y)
       y = y + 1;
    }
            
    /*@ assert y == n; */
}
