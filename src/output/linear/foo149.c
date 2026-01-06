
void foo149() {
    int x;
    int y;
    int i;
    int j;

    x = 0;
    y = 0;
    j = 0;
    i = 0;

    /*@
      loop invariant x == y;
      loop invariant i == x * (x + 1) / 2;
      loop invariant j >= y * (y + 1) / 2 && j <= y * (y + 3) / 2;
      loop assigns x, y, i, j;
    */
    while(unknown()) {
       x = x + 1;
       y = y + 1;
       i = x + i;
       if(unknown()) {
           j = y + j;
       }
       else {
           j = y + j + 1;
       }
    }
}
