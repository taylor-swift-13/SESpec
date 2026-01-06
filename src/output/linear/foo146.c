
void foo146() {
    int x;
    int y;

    x = 1;
    y = 0;

    /*@
      loop invariant ((y == 0)&&(x == 1)) || (x == 0);
      loop invariant y >= 0 && y <= 1024;
    */
    while(y < 1024){
       x = 0;
       y = y + 1;
    }

    /*@ assert x == 0; */
}
