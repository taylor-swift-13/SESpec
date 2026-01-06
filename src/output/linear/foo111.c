
/*@
    requires n >= 1;
    */
    
void foo111(int n) {

    int i = 1;
    int sn = 0;
    
    /*@
      loop invariant (1 <= \at(n,Pre)) ==> (i <= n + 1 && sn == i - 1);
      loop invariant (1 <= \at(n,Pre)) ==> (sn >= 0 && i >= 1);
      loop invariant (!(1 <= \at(n,Pre))) ==> ((sn == 0)&&(i == 1)&&(n == \at(n,Pre)));
      loop invariant n == \at(n,Pre);
      loop assigns sn, i;
    */
    while (i <= n) {
      i = (i + 1);
      sn = (sn + 1);
    }
    
    /*@ assert (sn!= 0) ==> (sn ==n); */
}
