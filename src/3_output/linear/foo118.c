
void foo118(int size) {
    int i = 1;
    int sn = 0;
    
    /*@
      loop invariant (1 <= \at(size,Pre)) ==> (sn == i - 1);
      loop invariant (1 <= \at(size,Pre)) ==> (i <= size + 1);
      loop invariant (!(1 <= \at(size,Pre))) ==> ((sn == 0)&&(i == 1)&&(size == \at(size,Pre)));
      loop invariant size == \at(size,Pre);
      loop assigns sn, i;
    */
    while (i <= size) {
        i = (i + 1);
        sn = (sn + 1);
    }
  
    /*@ assert (sn != size) ==> (sn == 0);*/
}
