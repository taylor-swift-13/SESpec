
void foo114() {
    int sn = 0;
    int x = 0;
    
    /*@
      loop invariant sn == x;
      loop invariant x >= 0 && sn >= 0;
      loop assigns sn, x;
    */
    while (unknown()) {
        x = (x + 1);
        sn = (sn + 1);
    }
    
    /*@ assert (sn != x) ==> (sn == -1);*/
}
