
void foo101(int n) {
    int x = 0;
    
    /*@
      loop invariant (0 < \at(n,Pre)) ==> (0 <= x <= \at(n,Pre));
      loop invariant (!(0 < \at(n,Pre))) ==> ((x == 0)&&(n == \at(n,Pre)));
      loop invariant n == \at(n,Pre);
      loop assigns x;
    */
    while (x < n) {
        x = (x + 1);
    }
    
    /*@ assert (x != n) ==> (n < 0); */
}
