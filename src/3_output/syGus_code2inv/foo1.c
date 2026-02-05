
void foo1() {
  
    int x = 1;
    int y = 0;
    
    /* >>> LOOP INVARIANT TO FILL <<< */
    
    /*@
      loop invariant x == (y * (y - 1)) / 2 + 1;
      loop invariant y >= 0;
      loop assigns x, y;
    */
    while (y < 100000) {
      
        x = x + y;
        y = y + 1;
      
    }
  
    /*@ assert x >= y; */
}
