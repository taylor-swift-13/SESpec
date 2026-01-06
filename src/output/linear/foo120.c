
void foo120() {
    int i = 1;
    int sn = 0;
    
    /*@
      loop invariant i == sn + 1;
      loop invariant sn == i - 1;
      loop invariant 1 <= i <= 9;
      loop invariant 0 <= sn <= 8;
      loop assigns i, sn;
    */
    while (i <= 8) {
        i = i + 1;
        sn = sn + 1;
    }
  
    /*@ assert (sn != 8) ==> (sn == 0);*/
}
