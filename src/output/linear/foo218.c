
void foo218() {
    int x;
    
    /*@ 
      loop invariant x % 8 == 0;
      loop assigns x;
    */
    while(unknown()) {
       x = x + 8;
    }
    
    /*@ assert (x % 8); */
}
