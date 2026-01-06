
void foo266() {
    int x;
    int y;
    int i;
    int j;
    int flag;

    x = 0;
    y = 0;
    i = 0;
    j = 0;

    /*@
      loop invariant x == y;
      loop invariant i == x*(x+1)/2;
      loop invariant flag != 0 ==> j >= y*(y+1)/2;
      loop invariant flag == 0 ==> j == y*(y+1)/2;
      loop assigns x, y, i, j;
    */
    while (unknown()) {
       x = x + 1;
       y = y + 1;
       i = i + x;
       j = j + y;
       if(flag != 0)
       j = j + 1;
    }

    /*@ assert j >= i; */
}
