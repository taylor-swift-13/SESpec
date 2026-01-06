
void foo25() {
    int x = 10000;
    
    /*@
      loop invariant x >= 0;
      loop invariant x <= 10000;
      loop assigns x;
    */
    while (x > 0) {
      x = x - 1;
    }
  
    /*@ assert x == 0; */
}
